//
//  26.sepc.swift
//  unittests
//
//  Created by litian on 3/6/22.
//

import Foundation
import XCTest

class LC26Sepc: XCTestCase {
    let sln26 = Solution26()
    
    func testCase1() throws {
        var nums = [1,1,2]
        let ret = sln26.removeDuplicates(&nums)
        
        XCTAssertTrue(ret == 2)
    }
    
    func testCase2() throws {
        var nums = [0,0,1,1,1,2,2,3,3,4]
        let ret = sln26.removeDuplicates(&nums)
        
        XCTAssertTrue(ret == 5)
    }
}
