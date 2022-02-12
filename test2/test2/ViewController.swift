//
//  ViewController.swift
//  test2
//
//  Created by LI Tian on 20/1/22.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var myView: UIView!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //Create a 200x200 view and a 50x50 button in code. Position the button in the center of the container.
        //let view = UIView(frame: CGRect(x: 0, y: 0, width: 200, height: 200))
        //let button = UIButton(type: .roundedRect)
//        button.frame = CGRect(x: 0, y: 0, width: 50, height: 50)
//        button.addConstraint(<#T##constraint: NSLayoutConstraint##NSLayoutConstraint#>)
//        view.addSubview(button)
//        UIViewAnimating()
        let array = ["dog", "cat", nil, "bird", "fish"]
        var count = 0;
        let _ = array.map{ each in
            count = count + 1
            print("\(count):\(each ?? "nil")")
        }
    }


}

