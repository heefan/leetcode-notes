import Foundation
import XCTest

class MyTestCase: XCTestCase {
    
    func testExample() {
        print("Test1")
        XCTAssertTrue(true)
    }
    
    func testAnother() {
        print("Test2")
        XCTAssertFalse(false)
    }
}

