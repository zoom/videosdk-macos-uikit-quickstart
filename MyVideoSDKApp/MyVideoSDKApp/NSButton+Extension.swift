//
//  NSButton+Extension.swift
//  MyVideoSDKApp

import Cocoa

class ImageAboveTextButton: NSButton {
    
    var spacing: CGFloat = 6 {
        didSet { updateTitleSpacing() }
    }
    
    convenience init(title: String, image: NSImage) {
        self.init(frame: .zero)
        self.title = title
        self.image = image
        commonInit()
    }
    
    override init(frame frameRect: NSRect) {
        super.init(frame: frameRect)
        commonInit()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        commonInit()
    }
    
    private func commonInit() {
        imagePosition = .imageAbove
        imageScaling = .scaleProportionallyUpOrDown
        alignment = .center
        font = NSFont.systemFont(ofSize: 20)
        bezelStyle = .flexiblePush
        isBordered = false
        updateTitleSpacing()
    }
    
    private func updateTitleSpacing() {
        let paragraph = NSMutableParagraphStyle()
        paragraph.alignment = .center
        
        let attrTitle = NSMutableAttributedString(string: title, attributes: [
            .font: font ?? NSFont.systemFont(ofSize: 14),
            .paragraphStyle: paragraph
        ])
        
        attrTitle.addAttribute(.baselineOffset, value: -spacing, range: NSRange(location: 0, length: attrTitle.length))
        
        attributedTitle = attrTitle
    }
}

extension NSImage {
    func resized(to newSize: NSSize) -> NSImage {
        let newImage = NSImage(size: newSize)
        newImage.lockFocus()
        self.draw(
            in: NSRect(origin: .zero, size: newSize),
            from: NSRect(origin: .zero, size: self.size),
            operation: .sourceOver,
            fraction: 1.0
        )
        newImage.unlockFocus()
        return newImage
    }
}
