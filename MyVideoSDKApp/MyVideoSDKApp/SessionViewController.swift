//
//  SessionViewController.swift
//  MyVideoSDKApp

import Cocoa
import ZMVideoSDK

class SessionViewController: NSViewController {
    // You should sign your JWT with a backend service in a production use-case
    let sdkKey = <#SDK Key#>
    let sdkSecret = <#SDK Secret#>
    let sessionName = <#Session Name#>
    let userName = <#Username#>
    
    // MARK: - Properties
    
    @IBOutlet weak var loadingView: NSView!
    @IBOutlet weak var progressIndicator: NSProgressIndicator!
    
    @IBOutlet weak var allUsersView: NSStackView!
    @IBOutlet weak var participantsHolderScrollView: NSScrollView!
    @IBOutlet weak var localUserView: NSView!
    @IBOutlet weak var ctaHolderView: NSView!
    @IBOutlet weak var ctaStackView: NSStackView!
    
    var remoteUsersStackView = NSStackView()
    
    var localPlaceholderView: NSView?
    
    var audioButton: ImageAboveTextButton!
    var videoButton: ImageAboveTextButton!
    var leaveButton: ImageAboveTextButton!
    
    var remoteUserViews: [String: (userView: NSView, placeholder: NSView)] = [:] {
        didSet {
            participantsHolderScrollView.isHidden = remoteUserViews.isEmpty
        }
    }
    
    // MARK: - Lifecycle Methods
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
        ZMVideoSDK.shared().addListener(self)
    }
    
    override func viewDidAppear() {
        super.viewDidAppear()
        Task {
            await joinSession()
        }
    }
    
    override func viewWillDisappear() {
        ZMVideoSDK.shared().removeListener(self)
    }
    
    // MARK: - Private Methods
    
    private func joinSession() async {
        let sessionContext = ZMVideoSDKSessionContext()
        do {
            let token = try await generateSignature(sessionName: sessionName, role: 1, sdkKey: sdkKey, sdkSecret: sdkSecret)
            sessionContext.token = token
            sessionContext.sessionName = sessionName
            sessionContext.userName = userName
            if ZMVideoSDK.shared().joinSession(sessionContext) == nil {
                showError(message: "Failed to join session")
                navigateBackToStartVC()
                return
            }
        } catch {
            showError(message: "Failed to generate session token: \(error.localizedDescription)")
            return
        }
    }
    
    @objc public func toggleAudio() {
        guard let myUser = ZMVideoSDK.shared().getSessionInfo().getMySelf(),
              let audioStatus = myUser.getAudioStatus() else { return }
        
        let audioHelper = ZMVideoSDK.shared().getAudioHelper()
        
        if audioStatus.audioType == .none {
            audioHelper.startAudio()
        } else {
            let _ = audioStatus.isMuted ? audioHelper.unMuteAudio(myUser) : audioHelper.muteAudio(myUser)
            setupAudioBtn(isMuted: audioStatus.isMuted)
        }
    }
    
    @objc public func toggleVideo() {
        guard let isVideoOn = ZMVideoSDK.shared().getSessionInfo().getMySelf()?.getVideoPipe()?.getVideoStatus()?.isOn else { return }
        
        let videoHelper = ZMVideoSDK.shared().getVideoHelper()
        
        DispatchQueue.main.async {
            let _ = isVideoOn ? videoHelper.stopVideo() : videoHelper.startVideo()
            self.setupVideoBtn(isVideoOn: !isVideoOn)
            self.localPlaceholderView?.isHidden = !isVideoOn
        }
    }
    
    @objc public func leaveSession() {
        showLoadingView(visible: true)
        ZMVideoSDK.shared().leaveSession(false)
    }
    
}

// MARK: - ZoomVideoSDKDelegate

extension SessionViewController: ZMVideoSDKDelegate {
    func onError(_ ErrorType: ZMVideoSDKErrors, detail details: Int32) {
        showError(message: "Error detected: \(ErrorType.rawValue)")
    }
    
    func onSessionJoin() {
        guard let myUser = ZMVideoSDK.shared().getSessionInfo().getMySelf(),
              let myUserVideoCanvas = myUser.getVideoCanvas() else { return }
        
        showLoadingView(visible: false)
        
        let videoHelper = ZMVideoSDK.shared().getVideoHelper()
        
        // Ensure video is started
        if !(myUser.getVideoPipe()?.getVideoStatus()?.isOn ?? false)
        {
            _ = videoHelper.startVideo()
        }
        
        myUserVideoCanvas.subscribe(with: self.localUserView, aspectMode: ZMVideoSDKVideoAspect_PanAndScan, resolution: ZMVideoSDKResolution_Auto)
        
        // Update UI to reflect video state
        addLocalViewToGrid()
        self.localPlaceholderView?.isHidden = true
        setupVideoBtn(isVideoOn: true)
    }
    
    func onSessionLeave(_ reason: ZMVideoSDKSessionLeaveReason) {
        navigateBackToStartVC()
    }
    
    func onUserJoin(_ userHelper: ZMVideoSDKUserHelper, userList userArray: [ZMVideoSDKUser]?) {
        guard let users = userArray, let myUser = ZMVideoSDK.shared().getSessionInfo().getMySelf() else { return }
        for user in users where user.getID() != myUser.getID() {
            if let currentUserID = user.getID(), let remoteUserVideoCanvas = user.getVideoCanvas() {
                let view = addRemoteUserView(for: user)
                remoteUserViews[currentUserID] = view
            }
        }
    }
    
    func onUserLeave(_ userHelper: ZMVideoSDKUserHelper, userList userArray: [ZMVideoSDKUser]?) {
        guard let users = userArray, let myUser = ZMVideoSDK.shared().getSessionInfo().getMySelf() else { return }
        for user in users where user.getID() != myUser.getID() {
            if let currentUserID = user.getID(), let view = remoteUserViews[currentUserID], let remoteUserVideoCanvas = user.getVideoCanvas() {
                Task(priority: .background) {
                    remoteUserVideoCanvas.unSubscribe(with: view.userView)
                    if let container = view.userView.superview {
                        container.removeFromSuperview()
                    }
                }
                remoteUserViews.removeValue(forKey: currentUserID)
            }
        }
    }
    
    func onUserVideoStatusChanged(_ videoHelper: ZMVideoSDKVideoHelper, userList userArray: [ZMVideoSDKUser]?) {
        guard let users = userArray, let myUser = ZMVideoSDK.shared().getSessionInfo().getMySelf() else { return }
        for user in users where user.getID() != myUser.getID() {
            if let currentUserID = user.getID(), let view = remoteUserViews[currentUserID], let isVideoOn = user.getVideoPipe()?.getVideoStatus()?.isOn, let remoteUserVideoCanvas = user.getVideoCanvas() {
                if isVideoOn {
                    print(remoteUserVideoCanvas.subscribe(with: view.userView, aspectMode: ZMVideoSDKVideoAspect_PanAndScan, resolution: ZMVideoSDKResolution_Auto))
                } else {
                    print(remoteUserVideoCanvas.unSubscribe(with: view.userView))
                }
                view.placeholder.isHidden = isVideoOn
            }
        }
    }
}
