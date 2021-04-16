//
//  ViewController.swift
//  ffmpegStudy
//
//  Created by 丰荣成 on 2021/4/16.
//

import Cocoa

class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let btn = NSButton.init(title: "test", target: self, action: #selector(testBtnClick))
        btn.frame = NSRect(x: 180, y: 120, width: 80, height: 40)
        btn.bezelStyle = .rounded
        btn.setButtonType(.pushOnPushOff)
        self.view.addSubview(btn)

        // Do any additional setup after loading the view.
    }
    @objc
    func testBtnClick(){
        print("test btn click")
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

