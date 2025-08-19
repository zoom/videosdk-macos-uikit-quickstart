//
//  Untitled.swift
//  MyVideoSDKApp

import Cocoa
import ZMVideoSDK

extension SessionViewController {
    
    public func setupUI() {
        showLoadingView(visible: true)
        
        participantsHolderScrollView.isHidden = true
        participantsHolderScrollView.hasHorizontalScroller = true
        participantsHolderScrollView.hasVerticalScroller = false
        participantsHolderScrollView.borderType = .noBorder
        participantsHolderScrollView.autohidesScrollers = true
        
        let clipView = NSClipView()
        clipView.documentView = remoteUsersStackView
        participantsHolderScrollView.contentView = clipView
        
        remoteUsersStackView.orientation = .horizontal
        remoteUsersStackView.spacing = 10
        remoteUsersStackView.translatesAutoresizingMaskIntoConstraints = false
        remoteUsersStackView.heightAnchor.constraint(equalTo: participantsHolderScrollView.heightAnchor).isActive = true
        
        progressIndicator.style = .spinning
        progressIndicator.isIndeterminate = true
        progressIndicator.startAnimation(nil)
        
        localUserView.wantsLayer = true
        localUserView.layer?.cornerRadius = 8
        
        let audioImage = NSImage(systemSymbolName: "mic.slash", accessibilityDescription: nil)!
        let fixedAudioImage = audioImage.resized(to: NSSize(width: 24, height: 24))
        
        let videoImage = NSImage(systemSymbolName: "video.slash", accessibilityDescription: nil)!
        let fixedVideoImage = videoImage.resized(to: NSSize(width: 24, height: 24))
        
        let leaveImage = NSImage(systemSymbolName: "phone.down", accessibilityDescription: nil)!
        let fixedLeaveImage = leaveImage.resized(to: NSSize(width: 24, height: 24))
        
        audioButton = ImageAboveTextButton(title: "Mute", image: fixedAudioImage)
        audioButton.action = #selector(toggleAudio)
        videoButton = ImageAboveTextButton(title: "Stop Video", image: fixedVideoImage)
        videoButton.action = #selector(toggleVideo)
        leaveButton = ImageAboveTextButton(title: "Leave", image: fixedLeaveImage)
        leaveButton.action = #selector(leaveSession)
        
        ctaStackView.addArrangedSubview(audioButton)
        ctaStackView.addArrangedSubview(videoButton)
        ctaStackView.addArrangedSubview(leaveButton)
        
        ctaHolderView.wantsLayer = true
        ctaHolderView.layer?.backgroundColor = NSColor.darkGray.withAlphaComponent(0.6).cgColor
        ctaHolderView.layer?.cornerRadius = 8
    }
    
    public func showLoadingView(visible: Bool) {
        loadingView.isHidden = !visible
        allUsersView.isHidden = visible
    }
    
    public func setupAudioBtn(isMuted: Bool) {
        let audioImage = NSImage(systemSymbolName: isMuted ? "mic.slash" : "mic", accessibilityDescription: nil)!
        let fixedAudioImage = audioImage.resized(to: NSSize(width: 24, height: 24))
        let newBtn = ImageAboveTextButton(title: isMuted ? "Mute" : "Unmute", image: fixedAudioImage)
        newBtn.action = #selector(self.toggleAudio)
        self.ctaStackView.replaceSubview(self.audioButton, with: newBtn)
        self.audioButton = newBtn
    }
    
    public func setupVideoBtn(isVideoOn: Bool) {
        let videoImage = NSImage(systemSymbolName: isVideoOn ? "video.slash" : "video", accessibilityDescription: nil)!
        let fixedVideoImage = videoImage.resized(to: NSSize(width: 24, height: 24))
        let newBtn = ImageAboveTextButton(title: isVideoOn ? "Stop Video" : "Start Video", image: fixedVideoImage)
        newBtn.action = #selector(self.toggleVideo)
        self.ctaStackView.replaceSubview(self.videoButton, with: newBtn)
        self.videoButton = newBtn
        self.localPlaceholderView?.isHidden = isVideoOn
    }
    
    public func showError(message: String) {
        if let window = NSApplication.shared.mainWindow {
            let alert = NSAlert()
            alert.messageText = "Error!"
            alert.informativeText = "An error has occured: \(message)"
            alert.alertStyle = .critical
            alert.addButton(withTitle: "OK")
            
            alert.beginSheetModal(for: window) { response in
                if response == .alertFirstButtonReturn {
                    print("User selected OK")
                }
            }
        }
    }
    
    public func addLocalViewToGrid() {
        let containerView = NSView()
        containerView.translatesAutoresizingMaskIntoConstraints = false
        containerView.wantsLayer = true
        containerView.layer?.backgroundColor = NSColor.black.cgColor
        
        let placeholder = createPlaceholderView(with: userName)
        localPlaceholderView = containerView
        containerView.addSubview(placeholder)
        localUserView.addSubview(containerView)
        
        NSLayoutConstraint.activate([
            // Fill container with localView
            localUserView.topAnchor.constraint(equalTo: containerView.topAnchor),
            localUserView.leadingAnchor.constraint(equalTo: containerView.leadingAnchor),
            localUserView.trailingAnchor.constraint(equalTo: containerView.trailingAnchor),
            localUserView.bottomAnchor.constraint(equalTo: containerView.bottomAnchor),
            
            // Fill container with placeholder
            placeholder.topAnchor.constraint(equalTo: containerView.topAnchor),
            placeholder.leadingAnchor.constraint(equalTo: containerView.leadingAnchor),
            placeholder.trailingAnchor.constraint(equalTo: containerView.trailingAnchor),
            placeholder.bottomAnchor.constraint(equalTo: containerView.bottomAnchor),
        ])
        
    }
    
    public func addRemoteUserView(for user: ZMVideoSDKUser) -> (userView: NSView, placeholder: NSView) {
        let containerView = NSView()
        containerView.translatesAutoresizingMaskIntoConstraints = false
        containerView.wantsLayer = true
        containerView.layer?.backgroundColor = NSColor.red.cgColor
        
        let userView = NSView()
        let placeholderView = createPlaceholderView(with: user.getName() ?? "")
        
        userView.translatesAutoresizingMaskIntoConstraints = false
        placeholderView.translatesAutoresizingMaskIntoConstraints = false
        
        containerView.addSubview(userView)
        containerView.addSubview(placeholderView)
        
        remoteUsersStackView.addArrangedSubview(containerView)
        
        NSLayoutConstraint.activate([
            // Keep the same aspect ratio
            containerView.heightAnchor.constraint(equalTo: remoteUsersStackView.heightAnchor, multiplier: 1.0),
            containerView.widthAnchor.constraint(equalToConstant: participantsHolderScrollView.frame.width * 0.35),
            
            // userView fills container
            userView.topAnchor.constraint(equalTo: containerView.topAnchor),
            userView.leadingAnchor.constraint(equalTo: containerView.leadingAnchor),
            userView.trailingAnchor.constraint(equalTo: containerView.trailingAnchor),
            userView.bottomAnchor.constraint(equalTo: containerView.bottomAnchor),
            
            // placeholderView fills container
            placeholderView.topAnchor.constraint(equalTo: containerView.topAnchor),
            placeholderView.leadingAnchor.constraint(equalTo: containerView.leadingAnchor),
            placeholderView.trailingAnchor.constraint(equalTo: containerView.trailingAnchor),
            placeholderView.bottomAnchor.constraint(equalTo: containerView.bottomAnchor),
        ])
        
        return (userView, placeholderView)
    }
    
    public func navigateBackToStartVC() {
        guard let window = view.window else { return }
        
        let currentFrame = window.frame
        
        let storyboard = NSStoryboard(name: "Main", bundle: nil)
        guard let newVC = storyboard.instantiateController(withIdentifier: "StartVC") as? StartViewController else { return }
        newVC.isSDKInitizlied = true
        NSAnimationContext.runAnimationGroup({ context in
            context.duration = 0.25
            self.view.animator().alphaValue = 0
        }, completionHandler: {
            window.contentViewController = newVC
            window.setFrame(currentFrame, display: true, animate: false)
            newVC.view.alphaValue = 0
            NSAnimationContext.runAnimationGroup({ context in
                context.duration = 0.25
                newVC.view.animator().alphaValue = 1
            })
        })
    }
    
    public func createPlaceholderView(with name: String) -> NSView {
        let placeholderView = NSView()
        placeholderView.translatesAutoresizingMaskIntoConstraints = false
        placeholderView.wantsLayer = true
        placeholderView.layer?.backgroundColor = NSColor.darkGray.cgColor
        
        let stackView = NSStackView()
        stackView.orientation = .vertical
        stackView.spacing = 8
        stackView.alignment = .centerX
        stackView.translatesAutoresizingMaskIntoConstraints = false
        
        let image = NSImage(systemSymbolName: "person.fill", accessibilityDescription: nil)
        let imageView = NSImageView(image: image ?? NSImage())
        imageView.translatesAutoresizingMaskIntoConstraints = false
        imageView.imageScaling = .scaleProportionallyUpOrDown
        imageView.contentTintColor = NSColor.white // Tint color for template image
        
        let label = NSTextField(labelWithString: name)
        label.textColor = NSColor.white
        label.font = NSFont.systemFont(ofSize: 16, weight: .medium)
        label.alignment = .center
        label.translatesAutoresizingMaskIntoConstraints = false
        
        stackView.addArrangedSubview(imageView)
        stackView.addArrangedSubview(label)
        placeholderView.addSubview(stackView)
        
        NSLayoutConstraint.activate([
            imageView.heightAnchor.constraint(equalToConstant: 50),
            imageView.widthAnchor.constraint(equalToConstant: 50),
            stackView.centerXAnchor.constraint(equalTo: placeholderView.centerXAnchor),
            stackView.centerYAnchor.constraint(equalTo: placeholderView.centerYAnchor),
        ])
        
        return placeholderView
    }
    
}
