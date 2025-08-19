//
//  AppDelegate.swift
//  MyVideoSDKApp

import Cocoa
import ZMVideoSDK

@main
class AppDelegate: NSObject, NSApplicationDelegate {
    
    var window: NSWindow?
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        if let screen = NSScreen.main {
            let screenFrame = screen.visibleFrame
            let newWidth = screenFrame.width * 0.75
            let newHeight = screenFrame.height * 0.75
            
            // Center position
            let originX = screenFrame.origin.x + (screenFrame.width - newWidth) / 2
            let originY = screenFrame.origin.y + (screenFrame.height - newHeight) / 2
            
            let newFrame = NSRect(x: originX, y: originY, width: newWidth, height: newHeight)
            
            if let window = NSApplication.shared.windows.first {
                window.setFrame(newFrame, display: true, animate: true)
                window.minSize = NSSize(width: newWidth, height: newHeight)
                window.title = "Video SDK macOS Quickstart App"
            }
        }
    }
    
    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }
    
    func applicationSupportsSecureRestorableState(_ app: NSApplication) -> Bool {
        return true
    }
    
}

