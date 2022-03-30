import UIKit

// kvo vs willSet/didSet

//KVO lets you implement the common “Observer” pattern. With KVO, you can attach any number of observers to a property, at run time, without modifying the source code of the property you're observing.
//
//Swift's willSet and didSet “observers” are essentially functions that are called before and after a property is set, and have to be written into the property's source code at compile time. They serve a very different purpose than KVO.
//https://stackoverflow.com/questions/47327363/swift-difference-between-kvo-and-willset-didset

