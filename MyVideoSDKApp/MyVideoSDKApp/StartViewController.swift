//
//  ViewController.swift
//  MyVideoSDKApp

import Cocoa
import ZMVideoSDK

class StartViewController: NSViewController {

    @IBOutlet weak var startJoinBtn: NSButton!
    
    var isSDKInitizlied: Bool? = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let cell = startJoinBtn.cell as? NSButtonCell {
            cell.font = NSFont.systemFont(ofSize: 40)
            startJoinBtn.sizeToFit()
        }
        
        setupSDK()
    }
    
    private func setupSDK() {
        guard isSDKInitizlied == false else { return }
        let initParams = ZMVideoSDKInitParams()
        initParams.domain = "https://zoom.us"
        initParams.logFilePrefix = "ZoomSDK"
        initParams.enableLog = true
        let sdkInitReturnStatus = ZMVideoSDK.shared().initialize(initParams)
        switch sdkInitReturnStatus {
        case ZMVideoSDKErrors_Success:
            print("SDK initialized successfully")
            isSDKInitizlied = true
        default:
            print("SDK failed to initialize: \(sdkInitReturnStatus)")
        }
    }

    @IBAction func clickStartJoinBtn(_ sender: NSButton) {
        guard let window = view.window else { return }
        
        let currentFrame = window.frame
        
        let storyboard = NSStoryboard(name: "Main", bundle: nil)
        guard let newVC = storyboard.instantiateController(withIdentifier: "SessionVC") as? NSViewController else { return }
        
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
}

extension StartViewController: ZMVideoSDKDelegate {
    func onError(_ ErrorType: ZMVideoSDKErrors, detail details: Int32) {
        switch ErrorType {
        case ZMVideoSDKErrors_Success:
            // Your ZMVideoSDK operation was successful.
            print("Success")
        default:
            // Your ZMVideoSDK operation raised an error.
            // Refer to error code documentation.
            print("Error \(ErrorType) \(details)")
            return
        }
    }
}
