//v2 framework preload js code 
//@preload-js-version 6.7.0.0
//@supported-client-version 6.7.0

try {
;(function () {
    'use strict';
    if (window.__ZM_INTERNALS__) {
        return;
    }

    if (!window.__ZM_INTERNALS__) {
        Object.defineProperty(window, '__ZM_INTERNALS__', {
            value: {}
        });
    }

    __ZM_IPC_FUNCTION__

    const UTILS = (function () {
        function generateUID() {
            return window.crypto.getRandomValues(new Uint32Array(1))[0];
        }
        
        function isInIframe() {
            return window.self !== window.top;
        }

        return {
            generateUID,
            isInIframe
        };
    })();

    const CALLBACK_MODULE = (function () {
        const callbacks = new Map();

        function registerCallback(callback, once = false) {
            const identifier = UTILS.generateUID();

            callbacks.set(identifier, (data) => {
                if (once) {
                    unregisterCallback(identifier);
                }
                return callback && callback(data);
            });

            return identifier;
        }

        function unregisterCallback(id) {
            callbacks.delete(id);
        }

        function runCallback(id, data) {
            const callback = callbacks.get(id);

            if (callback) {
                callback(data);
            }
        }

        return {
            registerCallback,
            unregisterCallback,
            runCallback,
            callbacks
        };
    })();

    const IPC_MODULE = (function () {
        const __ZM_INVOKE_KEY__ = "__ZM_INVOKE_KEY__VALUE__";
        const __ZM_CHECK_IFRAME_DOMAIN__ = __ZM_CHECK_IFRAME_DOMAIN_VALUE__;
        const __ZM_ALLOWED_DOMAINS__ = "^((https|http|zoomus|zoommtg|zoomroom|zoomrooms)://)?([a-zA-Z0-9._-]+\\.)?(zoom\\.us|zoomconnector\\.com|zoom\\.com(\\.cn)?|meetzoom\\.net|zoom\\.cn)(/.*)?$|^((https|http|zoomus|zoommtg|zoomroom|zoomrooms)://)?([a-zA-Z0-9._-]+\\.)?(zoomdev\\.us|zoomdev\\.de)(/.*)?$|^((https|http|zoomus|zoommtg|zoomroom|zoomrooms)://)?([a-zA-Z0-9._-]+\\.)?(zoomgov)\\.(com|mil)(/.*)?$|^((https|http|zoomus|zoommtg|zoomroom|zoomrooms)://)?([a-zA-Z0-9._-]+\\.)?(zipow|zoomgovdev|zoommildev)\\.com(/.*)?$|^((https|http|zoomus|zoommtg|zoomroom|zoomrooms)://)?([a-zA-Z0-9._-]+\\.)?(dog|dg01web|dg01www3)\\.zoom\\.us(/.*)?$|^((https|http|zoomus|zoommtg|zoomroom|zoomrooms)://)?([a-zA-Z0-9._-]+\\.)?(zoomdev|zoom)\\.com\\.cn(/.*)?$|^(https?://)?([a-zA-Z0-9._-]+\\.)?localhost(/.*)?$";
        let __ZM_ALLOWED_DOMAINS_REGEXP__ = null;
        let  inWebView = true;
        const FRAME_IPC_MODE = {
            NONE: 'none',
            DIRECT: 'direct',
            PROXY: 'proxy',
            DIRECT_OVER_PROXY: 'direct_over_proxy'
        };

        function isZoomDomain() {
            if (!__ZM_CHECK_IFRAME_DOMAIN__) {
                return true;
            }
            try {
                if (!__ZM_ALLOWED_DOMAINS_REGEXP__) {
                    __ZM_ALLOWED_DOMAINS_REGEXP__ = new RegExp(__ZM_ALLOWED_DOMAINS__);
                }
                var currentUrl = window.location.href || document.URL;
                return __ZM_ALLOWED_DOMAINS_REGEXP__.test(currentUrl);
            } catch (e) {
                return false;
            }
        }

        function isInWebView() {
            return inWebView;
        }

        async function checkConnection() {
            try {
                await window.__ZM_INTERNALS__.invoke('unifywebview', 'api', 'checkConnection', {}, { hybridIpcMode:"webview"})
                if (window.__ZM_INTERNALS__.setIpcReady) {
                    window.__ZM_INTERNALS__.setIpcReady(true);
                }
            }
            catch (error) {
                console.log('checkConnection error:', error)
            }
        }
      
        function randomString(length) {
            var chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
            var result = '';
            for (var i = 0; i < length; i++) {
                var randomIndex = Math.floor(Math.random() * chars.length);
                result += chars.charAt(randomIndex);
            }
            return result;
        }

        let frameIPCMode = FRAME_IPC_MODE.NONE;
        let frameId      = randomString(16);
        
        function setFrameIPCMode(mode) {
            if (!UTILS.isInIframe())
            {
                return false;
            }
            if (mode === FRAME_IPC_MODE.DIRECT) {
                frameIPCMode = FRAME_IPC_MODE.DIRECT_OVER_PROXY;
            } else {
                frameIPCMode = FRAME_IPC_MODE.PROXY;
            }
            return true;
        }
        setFrameIPCMode(FRAME_IPC_MODE.DIRECT);
        
        function processIpcMessage(message) {
            if (message instanceof ArrayBuffer || ArrayBuffer.isView(message) || Array.isArray(message)) {
                return { data: message };
            }

            const data = JSON.stringify(message, (_k, val) => {
                const SERIALIZE_TO_IPC_FN = '__ZM_TO_IPC_KEY__';

                if (val instanceof Map) {
                    return Object.fromEntries(val.entries());
                } else if (val instanceof Uint8Array) {
                    return Array.from(val);
                } else if (val instanceof ArrayBuffer) {
                    return Array.from(new Uint8Array(val));
                } else if (typeof val === 'object' && val !== null && SERIALIZE_TO_IPC_FN in val) {
                    return val[SERIALIZE_TO_IPC_FN]();
                }

                return val;
            });

            return { data };
        }

        function sendIpcMessage(message) {
            const { package: packageName, plugin, api, invokeId, callback, error, payload, options } = message;
            let messagePayload = {
                __ZM_INVOKE_KEY__,
                package: packageName,
                plugin,
                api,
                invokeId,
                callback,
                error,
                options: Object.assign({}, options),
                payload
            };

            if (frameIPCMode === FRAME_IPC_MODE.DIRECT_OVER_PROXY) {
                messagePayload.options.frameId = frameId;
                messagePayload.options.subFrameUrl = window.location.href || document.URL;
            }
            else if (frameIPCMode === FRAME_IPC_MODE.PROXY)
            {
                messagePayload.options.subFrameUrl = window.location.href || document.URL;
            }
            
            const { data } = processIpcMessage(messagePayload);
                if (UTILS.isInIframe()) {
                    if (!isZoomDomain()) {
                        return false;
                    }
                    if (frameIPCMode === FRAME_IPC_MODE.PROXY || frameIPCMode === FRAME_IPC_MODE.DIRECT_OVER_PROXY) {
                       window.parent.postMessage(data, '*');
                       return true;
                    } else {
                        console.error("frameIPCMode is error,value: ", frameIPCMode)
                        return false;
                    }
                } else {
                    if (!window.ipc || !window.ipc.postMessage) return false;
                    return window.ipc.postMessage(data, options);
                }
        }

        function handleDataRequestEvent(eventData) {
            if (!eventData.payload || !eventData.payload.replyId || eventData.payload.replyId.trim() === '') {
                return;
            }

            const purpose = eventData.payload && eventData.payload.payload && eventData.payload.payload.purpose;
            let responseData = null;

            switch (purpose) {
                case 'metrics':
                    responseData = window.__ZM_INTERNALS__.performance.getCurrentMetrics();
                    break;
                default:
                    break;
            }

            window.__ZM_INTERNALS__.invoke('unifywebview', 'event', 'reply', {
                replyId: eventData.payload.replyId,
                payload: responseData
            });
        }

        function registerDataRequestListener() {
            if (!isZoomDomain()) {
                return;
            }
            const handlerId = CALLBACK_MODULE.registerCallback((eventData) => {
                handleDataRequestEvent(eventData);
            });

            window.__ZM_INTERNALS__.invoke('unifywebview', 'event', 'listen', {
                event: 'data-request',
                package: 'unifywebview',
                handler: handlerId
            }).then((eventId) => {
                window.__ZM_INTERNALS__.registerEventListener('unifywebview', 'data-request', eventId, handlerId);
            }).catch((error) => {
                console.warn('Failed to listen to data-request event:', error);
            });
        }
       
        return {
            sendIpcMessage,
            checkConnection,
            setFrameIPCMode,
            registerDataRequestListener,
            isInWebView,
            isZoomDomain
        };
    })();

    const EVENT_MODULE = (function () {
        function initializeEventStorage() {
            if (!window.__zm_listeners__) {
                Object.defineProperty(window, '__zm_listeners__', {
                    value: Object.create(null)
                });
            }
        }

        function getPackageContainer(packageName) {
            if (!window.__zm_listeners__[packageName]) {
                Object.defineProperty(window.__zm_listeners__, packageName, {
                    value: Object.create(null),
                    configurable: true,
                    enumerable: true
                });
            }
            return window.__zm_listeners__[packageName];
        }

        function getEventContainer(packageContainer, eventName) {
            if (!packageContainer[eventName]) {
                Object.defineProperty(packageContainer, eventName, {
                    value: Object.create(null),
                    configurable: true,
                    enumerable: true
                });
            }
            return packageContainer[eventName];
        }

        function registerEventListener(packageName, eventName, eventId, handlerId) {
            initializeEventStorage();

            const packageContainer = getPackageContainer(packageName);
            const eventContainer = getEventContainer(packageContainer, eventName);

            const listener = {
                target: { kind: "Any" },
                handlerId: handlerId
            };

            Object.defineProperty(eventContainer, eventId, {
                value: listener,
                configurable: true,
                enumerable: true
            });
        }

        function unregisterListener(packageName, eventName, eventId) {
            if (!window.__zm_listeners__) return;

            const packageContainer = window.__zm_listeners__[packageName];
            if (!packageContainer) return;

            const eventContainer = packageContainer[eventName];
            if (!eventContainer) return;

            if (eventId === 0) {
                for (const id in eventContainer) {
                    if (eventContainer[id] && eventContainer[id].handlerId) {
                        CALLBACK_MODULE.unregisterCallback(eventContainer[id].handlerId);
                    }
                }
                delete packageContainer[eventName];

                if (Object.keys(packageContainer).length === 0) {
                    delete window.__zm_listeners__[packageName];
                }
            } else if (eventContainer[eventId]) {
                CALLBACK_MODULE.unregisterCallback(eventContainer[eventId].handlerId);
                delete eventContainer[eventId];

                if (Object.keys(eventContainer).length === 0) {
                    delete packageContainer[eventName];

                    if (Object.keys(packageContainer).length === 0) {
                        delete window.__zm_listeners__[packageName];
                    }
                }
            }
        }

        function handleIncomingEvent(eventData, ids) {
            if (!eventData.package || !window.__zm_listeners__) return;

            const packageContainer = window.__zm_listeners__[eventData.package];
            if (!packageContainer) return;

            const eventContainer = packageContainer[eventData.event];
            if (eventContainer) {
                for (const id of ids) {
                    const listener = eventContainer[id];
                    if (listener) {
                        eventData.id = id;
                        CALLBACK_MODULE.runCallback(listener.handlerId, eventData);
                    }
                }
            }

            const wildcardContainer = packageContainer['*'];
            if (wildcardContainer) {
                const propertyNames = Object.getOwnPropertyNames(wildcardContainer);
                for (const eventId of propertyNames) {
                    const listener = wildcardContainer[eventId];
                    if (listener && listener.handlerId) {
                        eventData.id = parseInt(eventId); // Convert to number if needed
                        CALLBACK_MODULE.runCallback(listener.handlerId, eventData);
                    }
                }
            }
        }

        return {
            registerEventListener,
            unregisterListener,
            handleIncomingEvent
        };
    })();

    function executeHandler(handler, data, invokeId, setResult) {
        const handleError = (error) => {
            setResult(invokeId, null, error && error.message ? error.message : String(error));
        };

        try {
            const result = handler(data);
            
            if (result && typeof result.then === 'function') {
                result.then((asyncResult) => {
                    setResult(invokeId, asyncResult, null);
                }).catch(handleError);
            } else {
                setResult(invokeId, result, null);
            }
        } catch (error) {
            handleError(error);
        }
    }

    const INVOKE_MODULE = (function () {
       
        class HybridError extends Error {
            constructor(code, message, invokeId) {
                super(code);
                this.code = code;
                this.message = message;
                this.invokeId = invokeId;
                if (typeof Error.captureStackTrace === "function") {
                    Error.captureStackTrace(this, HybridError);
                } else {
                    this.stack = (new Error(message)).stack;
                }
            }
        }

        const DEFAULT_TIMEOUT = 90 * 1000;

        function invoke(packageName, plugin, api, payload = {}, options = {}) {
            return new Promise((resolve, reject) => {
                const requestSize = JSON.stringify(payload).length;
                
                const callback = CALLBACK_MODULE.registerCallback((result) => {
                    clearTimeout(timeoutId);
                    
                    if (window.__ZM_INTERNALS__.debug) {
                        const responseSize = JSON.stringify(result).length;
                        window.__ZM_INTERNALS__.debug.storeApiCall({
                            package: packageName,
                            plugin: plugin,
                            api: api,
                            invokeId: invokeId,
                            requestSize: requestSize,
                            responseSize: responseSize,
                            code: 'NoError',
                            message: ''
                        });
                    }
                    
                    resolve(result);
                    CALLBACK_MODULE.unregisterCallback(error);
                }, true);

                const error = CALLBACK_MODULE.registerCallback((err) => {
                    clearTimeout(timeoutId);
                    
                    if (window.__ZM_INTERNALS__.debug) {
                        const errorResponseSize = JSON.stringify(err).length;
                        window.__ZM_INTERNALS__.debug.storeApiCall({
                            package: packageName,
                            plugin: plugin,
                            api: api,
                            invokeId: invokeId,
                            requestSize: requestSize,
                            responseSize: errorResponseSize,
                            code: err.code,
                            message: err.message
                        });
                    }
                    
                    reject(new HybridError(err.code,err.message, invokeId));
                    CALLBACK_MODULE.unregisterCallback(callback);
                }, true);

                const now = new Date();
                const timestamp = now.getFullYear().toString() + '-' +
                    (now.getMonth() + 1).toString().padStart(2, '0') + '-' +
                    now.getDate().toString().padStart(2, '0') + '_' +
                    now.getHours().toString().padStart(2, '0') + ':' +
                    now.getMinutes().toString().padStart(2, '0') + ':' +
                    now.getSeconds().toString().padStart(2, '0') + '_' +
                    now.getMilliseconds().toString().padStart(3, '0');
                const randomNum = Math.floor(Math.random() * 10000000);
                const invokeId = `${packageName}:${plugin}/${api}_${timestamp}_${randomNum}`;
                
                const startTime = Date.now();
                if (window.__ZM_INTERNALS__.debug) {
                    window.__ZM_INTERNALS__.debug.storeApiCall({
                        package: packageName,
                        plugin: plugin,
                        api: api,
                        invokeId: invokeId,
                        requestSize: requestSize,
                        startTime: startTime
                    });
                }

                const timeout = options.timeout * 1000 || DEFAULT_TIMEOUT;
                const timeoutId = setTimeout(() => {
                    window.__ZM_INTERNALS__.runCallback(error, { code: 'HybridError_JavascriptTimeout',message:''});
                }, timeout);

                window.__ZM_INTERNALS__.ipc({
                    package: packageName,
                    plugin,
                    api,
                    invokeId,
                    callback,
                    error,
                    payload,
                    options
                });
            });
        }

        const frontendHandlers = new Map();

        function registerFrontendHandler(params) {
            for (const [handlerId, handlerInfo] of frontendHandlers.entries()) {
                if (handlerInfo.package === params.package && 
                    handlerInfo.plugin === params.plugin && 
                    handlerInfo.api === params.api) {
                    return Promise.reject(new HybridError('RepeatedInvoke', 'API already registered'));
                }
            }
            
            const handlerId = window.__ZM_INTERNALS__.transformCallback(params.handler);
            
            return window.__ZM_INTERNALS__.invoke('unifywebview', 'api', 'registerInvoke', {
                params: {
                    package: params.package,
                    plugin: params.plugin,
                    api: params.api,
                    handlerId: handlerId
                }
            }).then((result) => {
                if (result) {
                    frontendHandlers.set(handlerId, {
                        handler: params.handler,
                        package: params.package,
                        plugin: params.plugin,
                        api: params.api
                    });
                }
                return result;
            });
        }

        function unregisterFrontendHandler(params) {
            return window.__ZM_INTERNALS__.invoke('unifywebview', 'api', 'unregisterInvoke', {
                params: {
                    package: params.package,
                    plugin: params.plugin,
                    api: params.api
                }
            }).then((result) => {
                if (result) {
                    for (const [handlerId, handlerInfo] of frontendHandlers.entries()) {
                        if (handlerInfo.package === params.package && 
                            handlerInfo.plugin === params.plugin && 
                            handlerInfo.api === params.api) {
                            frontendHandlers.delete(handlerId);
                            break;
                        }
                    }
                }
                return result;
            });
        }


        function executeFrontendHandler(handlerId, data, invokeId) {
            const handlerInfo = frontendHandlers.get(handlerId);
            if (!handlerInfo) {
                setInvokeResult(invokeId, null, 'Frontend handler not found');
                return;
            }


            if (handlerInfo.isFromIframe) {
                data.invokeId = invokeId;
                handlerInfo.handler(data);
                return;
            }
            
            executeHandler(handlerInfo.handler, data, invokeId, setInvokeResult);
        }

        function setInvokeResult(invokeId, result, error) {
            window.__ZM_INTERNALS__.invoke('unifywebview', 'api', 'frontendResponse', {
                params: {
                    invokeId: invokeId,
                    payload: result,
                    error: error || ''
                }
            });
        }

        return { 
            invoke,
            executeFrontendHandler,
            registerFrontendHandler,
            setInvokeResult,
            unregisterFrontendHandler,
            frontendHandlers
        };
    })();

    const MESSAGE_HANDLER = (function () {
        function handleParentMessage(event) {
            if (event.source !== window.parent) return;

            const messageData = event.data;
            if (messageData && messageData.type === '__zm_run_unifysdk_callback__') {
                const { callbackId, data } = messageData;
                CALLBACK_MODULE.runCallback(callbackId, data);
            }
            else if (messageData && messageData.type === '__zm_execute_frontend_handler__') {
                const handlerInfo = INVOKE_MODULE.frontendHandlers.get(messageData.handlerId);
                if (handlerInfo) {
                    executeHandler(handlerInfo.handler, messageData.data, messageData.data.invokeId, INVOKE_MODULE.setInvokeResult);
                } else {
                    INVOKE_MODULE.setInvokeResult(messageData.invokeId, null, 'Frontend handler not found');
                }
            }
        }

        function handleChildMessage(event) {
            if (!event.source || !event.data) return;

            try {
                let messageData = event.data;
                if (typeof messageData === 'string') {
                    messageData = JSON.parse(messageData);
                }

                if (messageData.options && messageData.options.subFrameUrl) {
                    let originError = null;
                    try {
                        const subFrameOrigin = new URL(messageData.options.subFrameUrl).origin;
                        if (event.origin !== subFrameOrigin) {
                            originError = 'Origin mismatch';
                        }
                    } catch (e) {
                        originError = 'Invalid subFrameUrl';
                    }
                    if (originError) {
                        console.error('[UnifyWebView]', originError, '- event.origin:', event.origin, ', subFrameUrl:', messageData.options.subFrameUrl);
                        if (messageData.error && event.source) {
                            event.source.postMessage({
                                type: '__zm_run_unifysdk_callback__',
                                callbackId: messageData.error,
                                data: { code: 'NoPermission', message: originError }
                            }, '*');
                        }
                        return;
                    }
                }

                if (messageData.api === 'registerInvoke')
                {
                    const originalHandlerId = messageData.payload.params.handlerId;
                    const newHandlerId = CALLBACK_MODULE.registerCallback((data) => {
                        event.source.postMessage({
                            type: '__zm_execute_frontend_handler__',
                            handlerId: originalHandlerId,
                            data: data
                        }, '*');
                    });
                    const { package: packageName, plugin, api } = messageData.payload.params;
                    INVOKE_MODULE.frontendHandlers.set(newHandlerId, {
                        handler: (data) => CALLBACK_MODULE.runCallback(newHandlerId, data),
                        package: packageName,
                        plugin: plugin,
                        api: api,
                        isFromIframe: true
                    });
                    messageData.payload.params.handlerId = newHandlerId;
                }
                if (messageData && messageData.api && window.__ZM_INTERNALS__) {
                    window.__ZM_INTERNALS__.invoke(messageData.package, messageData.plugin,
                        messageData.api, messageData.payload, messageData.options, messageData.topFrameOrigin)
                        .then((result) => {
                            if (messageData.callback) {
                                if (messageData.api === 'listen') {
                                    const handlerId = CALLBACK_MODULE.registerCallback((eventData) => {
                                        event.source.postMessage({
                                            type: '__zm_run_unifysdk_callback__',
                                            callbackId: messageData.payload.handler,
                                            data: eventData
                                        }, '*');
                                    });
                                    EVENT_MODULE.registerEventListener(
                                        messageData.payload.package,
                                        messageData.payload.event,
                                        result,
                                        handlerId
                                    );
                                }
                                else if (messageData.api === 'unlisten') {
                                    EVENT_MODULE.unregisterListener(
                                        messageData.payload.package,
                                        messageData.payload.event,
                                        messageData.payload.eventId
                                    );
                                }
                                else if (messageData.api === 'unregisterInvoke') {
                                    const { package: packageName, plugin, api } = messageData.payload.params;
                                    for (const [handlerId, handlerInfo] of INVOKE_MODULE.frontendHandlers.entries()) {
                                        if (handlerInfo.package === packageName &&
                                            handlerInfo.plugin === plugin &&
                                            handlerInfo.api === api) {
                                            INVOKE_MODULE.frontendHandlers.delete(handlerId);
                                        }
                                    }
                                }

                                event.source.postMessage({
                                    type: '__zm_run_unifysdk_callback__',
                                    callbackId: messageData.callback,
                                    data: result
                                }, '*');
                            }
                        })
                        .catch((error) => {
                            if (messageData.error) {
                                event.source.postMessage({
                                    type: '__zm_run_unifysdk_callback__',
                                    callbackId: messageData.error,
                                    data: { code: error.code, message: error.message}
                                }, '*');
                            }
                        });
                }
            } catch (error) {
            }
        }

        function initializeMessageHandlers() {
            if (UTILS.isInIframe()) {
                window.addEventListener('message', handleParentMessage);
            } else {
                window.addEventListener('message', handleChildMessage);
            }
        }

        return { initializeMessageHandlers };
    })();

    const DEBUG_MODULE = (function () {
        let errorHistory = [];
        let apiCallHistory = new Map();
        let invokeTimeMap = new Map();
        
        function storeApiCall(apiCallInfo) {
            if (apiCallInfo.startTime) {
                invokeTimeMap.set(apiCallInfo.invokeId, apiCallInfo.startTime);
                return;
            }
            
            if (apiCallInfo.code && apiCallInfo.code != 'NoError') {
                errorHistory.push({
                    invokeId: apiCallInfo.invokeId,
                    code: apiCallInfo.code,
                    message: apiCallInfo.message
                });
            }
            
            const startTime = invokeTimeMap.get(apiCallInfo.invokeId);
            const endTime = Date.now();
            const duration = startTime ? endTime - startTime : 0;
            
            invokeTimeMap.delete(apiCallInfo.invokeId);
            
            const key = `${apiCallInfo.package}:${apiCallInfo.plugin}:${apiCallInfo.api}`;
            
            if (!apiCallHistory.has(key)) {
                apiCallHistory.set(key, {
                    stats: {
                        maxDuration: 0,
                        minDuration: 0,
                        avgDuration: 0,
                        callCount: 0,
                        failedCount: 0,
                        totalRequestSize: 0,
                        totalResponseSize: 0
                    }
                });
            }
            
            const apiData = apiCallHistory.get(key);
            const stats = apiData.stats;
            
            const requestSize = apiCallInfo.requestSize || 0;
            const responseSize = apiCallInfo.responseSize || 0;
            
            stats.callCount++;
            stats.totalRequestSize += requestSize;
            stats.totalResponseSize += responseSize;
            
            if (apiCallInfo.code && apiCallInfo.code != 'NoError') {
                stats.failedCount++;
            }
            
            if (stats.callCount === 1) {
                stats.maxDuration = duration;
                stats.minDuration = duration;
                stats.avgDuration = duration;
            } else {
                stats.maxDuration = Math.max(stats.maxDuration, duration);
                stats.minDuration = Math.min(stats.minDuration, duration);
                stats.avgDuration = Math.round(((stats.avgDuration * (stats.callCount - 1)) + duration) / stats.callCount * 100) / 100;
            }
        }

        function getErrorHistory() {
            return [...errorHistory];
        }

        function getApiCallHistory() {
            return new Map(apiCallHistory);
        }
        
        function clearErrorHistory() {
            errorHistory = [];
        }

        function clearApiCallHistory() {
            apiCallHistory.clear();
        }

        function clearAllHistory() {
            errorHistory = [];
            apiCallHistory.clear();
        }

        return {
            storeApiCall,
            getErrorHistory,
            clearErrorHistory,
            getApiCallHistory,
            clearApiCallHistory,
            clearAllHistory
        };
    })();

    const PERFORMANCE_MODULE = (function () {
        const round = (n) => Math.round(n);

        let isInitialReportDone = false;
        let reportTimer = null;

        function reportMetrics() {
            if (!isInitialReportDone || !IPC_MODULE.isZoomDomain()) {
                return;
            }
            if (reportTimer) {
                clearTimeout(reportTimer);
            }
            reportTimer = setTimeout(() => {
                window.__ZM_INTERNALS__.invoke('unifywebview', 'api', 'reportMetrics', { params: JSON.stringify(getCurrentMetrics()) })
                    .catch((error) => {
                        console.error('[reportMetrics] failed:', error);
                    });
                reportTimer = null;
            }, 60000);
        }

        const metrics = {
            first_paint: null,             
            first_contentful_paint: null,           
            largest_contentful_paint: null,
            body_is_null:false,
            web_center_is_null: false,
            web_center_element_tree: null,
            long_tasks: [],        
            total_block_time: 0, 
            script_load_error: [],
            resource_error: [],
            resource_longtime: [],
            first_input: [],
            visibility_state: [],
            routes: [],
            navigation: null,
            unhandledrejection: [],
            js_error: [],
            memory: null
        };

        function setMetricField(key, value) {
            const oldValue = metrics[key];
            metrics[key] = value;
            if (oldValue !== value) {
                reportMetrics();
            }
        }

        function pushMetricField(key, payload) {
            if (!Array.isArray(metrics[key])) {
                metrics[key] = [];
            }
            metrics[key].push(payload);
            if (metrics[key].length > 50) {
                metrics[key].shift();
            }
            reportMetrics();
        }

        function initHistoryHook()
        {
            const originalPushState = history.pushState;
            const originalReplaceState = history.replaceState;

            function handleRouteChange(type) {
                pushMetricField('routes', {
                    type,
                    url: location.href,
                    time: Date.now()
                });
            }

            history.pushState = function (...args) {
                originalPushState.apply(this, args);
                handleRouteChange('pushState');
            };

            history.replaceState = function (...args) {
                originalReplaceState.apply(this, args);
                handleRouteChange('replaceState');
            };

            window.addEventListener('popstate', () => handleRouteChange('popstate'));
        }

        function initializePerformanceObservers() {
            try {
                // Detect Mac/WebKit platform from unifyConfig
                const isMacWebKit = window.unifyConfig && 
                                    window.unifyConfig.systemParam && 
                                    window.unifyConfig.systemParam.deviceOs === 'mac' && 
                                    window.unifyConfig.systemParam.webviewName === 'WebKit';
                
                const ob = new PerformanceObserver((list) => {
                    for (const entry of list.getEntries()) {
                        if (entry.entryType === 'resource')
                        {
                            // Mac/WebKit doesn't provide responseStatus in Performance API
                            // Use alternative indicators for error detection
                            if (isMacWebKit) {
                                // Detect potential resource errors using available metrics on Mac
                                // Safe access to properties that may be undefined in older Safari versions
                                const transferSize = entry.transferSize || 0;
                                const encodedBodySize = entry.encodedBodySize || 0;
                                const nextHopProtocol = entry.nextHopProtocol || '';
                                
                                const isPotentialError = (
                                    // Response never completed
                                    entry.responseEnd === 0 ||
                                    // Zero duration with zero transfer size might indicate failure (except cached resources)
                                    (entry.duration === 0 && transferSize === 0 && entry.fetchStart === 0) ||
                                    // Cross-origin resource with no timing data (CORS issue or failure)
                                    (transferSize === 0 && 
                                     encodedBodySize === 0 && 
                                     entry.duration > 0 && 
                                     entry.responseStart === 0 &&
                                     entry.name.indexOf('.map') !== entry.name.length - 4) // Exclude source maps
                                );
                                
                                if (isPotentialError) {
                                    pushMetricField('resource_error', {
                                        url: entry.name, 
                                        duration: entry.duration, 
                                        load_start: entry.startTime, 
                                        transferSize: transferSize,
                                        nextHopProtocol: nextHopProtocol,
                                        time: Date.now()
                                    });
                                }
                                else if (entry.duration > 500 && entry.name.indexOf('.js') === entry.name.length - 3)
                                {
                                    pushMetricField('resource_longtime', {
                                        url: entry.name, 
                                        duration: entry.duration, 
                                        load_start: entry.startTime, 
                                        transferSize: transferSize,
                                        time: Date.now()
                                    });
                                }
                            } else {
                                // Other platforms: use responseStatus if available
                                if ((entry.responseStatus != 200 && entry.responseStatus != 0)) {
                                    pushMetricField('resource_error', {
                                        url: entry.name, duration: entry.duration, load_start: entry.startTime, responseStatus: entry.responseStatus, time: Date.now()
                                    });
                                }
                                else if (entry.duration > 100)
                                {
                                    pushMetricField('resource_longtime', {
                                        url: entry.name,
                                        duration: entry.duration,
                                        load_start: entry.startTime,
                                        responseStatus: entry.responseStatus,
                                        time: Date.now()
                                    });
                                }
                            }
                        }
                        else if (entry.entryType === 'paint')
                        {
                            if (entry.name === 'first-paint') {
                                setMetricField('first_paint', entry.startTime);
                            } else if (entry.name === 'first-contentful-paint') {
                                setMetricField('first_contentful_paint', entry.startTime);
                            }
                        }
                        else if (entry.entryType === 'event') {
                        }
                        else if (entry.entryType === 'longtask') {
                            pushMetricField('long_tasks', {
                                name: entry.name,
                                startTime: entry.startTime,
                                duration: entry.duration,
                                time: Date.now()
                            });
                        }
                        else if (entry.entryType === 'navigation') {
                            setMetricField('navigation', {
                                url: entry.name,
                                duration: entry.duration,
                                activationStart: entry.activationStart,
                                connectStart: entry.connectStart,
                                connectEnd: entry.connectEnd,
                                decodedBodySize: entry.decodedBodySize,
                                encodedBodySize: entry.encodedBodySize,
                                firstInterimResponseStart: entry.firstInterimResponseStart,
                                finalResponseHeadersStart: entry.finalResponseHeadersStart,
                                redirectCount: entry.redirectCount,
                                redirectStart: entry.redirectStart,
                                redirectEnd: entry.redirectEnd,
                                requestStart: entry.requestStart,
                                responseStart: entry.responseStart,
                                responseEnd: entry.responseEnd,
                                responseStatus: entry.responseStatus,
                                unloadEventEnd: entry.unloadEventEnd,
                                unloadEventStart: entry.unloadEventStart,
                                initiatorType: entry.initiatorType,
                                domContentLoadedEventStart: entry.domContentLoadedEventStart,
                                domComplete: entry.domComplete,
                                domainLookupStart: entry.domainLookupStart,
                                domainLookupEnd: entry.domainLookupEnd,
                                loadEventStart: entry.loadEventStart,
                                loadEventEnd: entry.loadEventEnd,
                                fetchStart: entry.fetchStart
                            });
                        }
                        else if (entry.entryType === 'first-input') {
                            setMetricField('first_input', {
                                name: entry.name,
                                startTime: entry.startTime,
                                time: Date.now()
                            });
                        }
                        else if (entry.entryType === 'largest-contentful-paint') {
                            setMetricField('largest_contentful_paint', entry.startTime);
                        }
                        else if (entry.entryType === 'visibility-state') {
                            pushMetricField('visibility_state', {
                                name: entry.name,
                                startTime: entry.startTime,
                                time: Date.now()
                            });
                        }
                    }
                });
               
                ob.observe({
                    entryTypes: ['resource', 'longtask', 'paint', 'navigation', 'first-input', 'largest-contentful-paint', 'visibility-state', 'event']
                });
            } catch (e) {
               
            }

            window.addEventListener('unhandledrejection', (event) => {
                pushMetricField('unhandledrejection', {
                    reason: event.reason,
                    promise: event.promise
                });
            });

            window.addEventListener('error', (event) => {
                if (event.target && event.target !== window)
                {
                    if (event.target.tagName === 'SCRIPT') {
                        pushMetricField('script_load_error', { url: event.target.src, time: Date.now() })
                    }
                }
                else {
                    pushMetricField('js_error', {
                        message: event.message,
                        filename: event.filename,
                        lineno: event.lineno,
                        colno: event.colno,
                        error: event.error 
                    });
                }
            }, true); 
        }

        /**
        * Get current performance metrics
        */
        function getElementInfo() {
            if (document.body.children.length === 0) {
                setMetricField('body_is_null', true);
            }
            else {
                const screenWidth = window.innerWidth;
                const screenHeight = window.innerHeight;

                const rows = 5;
                const cols = 5;
                const samplePoints = [];
                for (let i = 0; i < rows; i++) {
                    for (let j = 0; j < cols; j++) {
                        const x = ((j + 0.5) / cols) * screenWidth;
                        const y = ((i + 0.5) / rows) * screenHeight;
                        samplePoints.push({ x, y });
                    }
                }

                let maxDepth = 0;
                for (const point of samplePoints) {
                    const elements = document.elementsFromPoint(point.x, point.y);

                    if (elements.length > maxDepth) {
                        setMetricField('web_center_element_tree', elements.map(e => e.tagName).join('<'));
                        maxDepth = elements.length;
                    }
                }

                if (maxDepth <= 2) {
                    setMetricField('web_center_is_null', true);
                }
            }
        }

        function startPerformanceMonitoring() {
            initHistoryHook()
            initializePerformanceObservers();

            window.addEventListener('load', () => {
                if (!IPC_MODULE.isZoomDomain()) return;
                setTimeout(() => {
                    getElementInfo()
                    window.__ZM_INTERNALS__.invoke('unifywebview', 'api', 'reportMetrics', { params: JSON.stringify(getCurrentMetrics()) })
                        .then(() => {
                            isInitialReportDone = true;
                        })
                        .catch((error) => {
                            console.error('[reportMetrics] failed:', error);
                            isInitialReportDone = true;
                        });
                }, 5000);
            });
        }

        const SENSITIVE_PARAM_RE = /([?&])(jwt|access_token|token|tokenType|deviceId|requestToken|secret|password|access_key|api_key|authorization)=([^&]*)/gi;

        const SENSITIVE_KEYS = [
            'authorization', 'cookie', 'set-cookie',
            'x-zm-token', 'x-csrf-token', 'x-xsrf-token',
            'token', 'access_token', 'jwt', 'password', 'secret',
            'api_key', 'access_key', 'requesttoken'
        ];

        function redactUrl(url) {
            if (typeof url !== 'string') return url;
            return url.replace(SENSITIVE_PARAM_RE, function (_, prefix, key, _value) {
                return prefix + key + '=[REDACTED]';
            });
        }

        function isSensitiveKey(key) {
            var lower = key.toLowerCase();
            for (var i = 0; i < SENSITIVE_KEYS.length; i++) {
                if (lower === SENSITIVE_KEYS[i]) return true;
            }
            return false;
        }

        var MAX_REDACT_DEPTH = 20;

        function removeSensitiveInfo(value, parentKey, _seen, _depth) {
            try {
                if (value == null) return value;
                if (parentKey && isSensitiveKey(parentKey)) return '[REDACTED]';
                if (typeof value === 'string') return redactUrl(value);
                if (typeof value === 'object') {
                    if (_depth == null) _depth = 0;
                    if (_depth >= MAX_REDACT_DEPTH) return '[MaxDepth]';
                    if (!_seen) _seen = new WeakSet();
                    if (_seen.has(value)) return '[Circular]';
                    _seen.add(value);
                    if (Array.isArray(value)) return value.map(function (item) { return removeSensitiveInfo(item, undefined, _seen, _depth + 1); });
                    var result = {};
                    for (var k in value) {
                        if (Object.prototype.hasOwnProperty.call(value, k)) {
                            result[k] = removeSensitiveInfo(value[k], k, _seen, _depth + 1);
                        }
                    }
                    return result;
                }
                return value;
            } catch (e) {
                return value;
            }
        }

        function getCurrentMetrics() {
            setMetricField('url', location.href);
            setMetricField('visibilityState', document.visibilityState);
            if (performance && performance.memory) {
                metrics.memory = {
                    usedJSHeapSize: Math.round(performance.memory.usedJSHeapSize / (1024 * 1024)),
                    totalJSHeapSize: Math.round(performance.memory.totalJSHeapSize / (1024 * 1024)),
                    jsHeapSizeLimit: Math.round(performance.memory.jsHeapSizeLimit / (1024 * 1024))
                };
            }
            return removeSensitiveInfo(metrics);
        }

        return {
            startPerformanceMonitoring,
            getCurrentMetrics
        };
    })();


    Object.defineProperty(window.__ZM_INTERNALS__, 'ipc', {
        value: IPC_MODULE.sendIpcMessage
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'setFrameIPCMode', {
        value: IPC_MODULE.setFrameIPCMode
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'isInWebView', {
        value: IPC_MODULE.isInWebView
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'transformCallback', {
        value: CALLBACK_MODULE.registerCallback
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'unregisterCallback', {
        value: CALLBACK_MODULE.unregisterCallback
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'runCallback', {
        value: CALLBACK_MODULE.runCallback
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'callbacks', {
        value: CALLBACK_MODULE.callbacks
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'registerEventListener', {
        value: EVENT_MODULE.registerEventListener
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'unregisterListener', {
        value: EVENT_MODULE.unregisterListener
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'invoke', {
        value: INVOKE_MODULE.invoke
    });

    Object.defineProperty(window, '__zm_listeners_id__', {
        value: EVENT_MODULE.handleIncomingEvent
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'performance', {
        value: PERFORMANCE_MODULE
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'debug', {
        value: DEBUG_MODULE
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'executeFrontendHandler', {
        value: INVOKE_MODULE.executeFrontendHandler
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'registerFrontendHandler', {
        value: INVOKE_MODULE.registerFrontendHandler
    });

    Object.defineProperty(window.__ZM_INTERNALS__, 'unregisterFrontendHandler', {
        value: INVOKE_MODULE.unregisterFrontendHandler
    });

   
    MESSAGE_HANDLER.initializeMessageHandlers();
    PERFORMANCE_MODULE.startPerformanceMonitoring();

    window.addEventListener('DOMContentLoaded', () => {
        if (!UTILS.isInIframe()) {
            IPC_MODULE.registerDataRequestListener();
            IPC_MODULE.checkConnection();
        }
    });

   

})(); // End of main IIFE

} catch (error) {
    console.error('preload js execution failed:', error);
}
