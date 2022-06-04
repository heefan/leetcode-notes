//
//  LC33.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation
import XCTest

class LC33: XCTestCase {
    let sln33 = Solution33()
    
    func testCase1() throws {
        let nums = [4,5,6,7,0,1,2]
        let ret = sln33.search(nums, 0)
        
        XCTAssertTrue(ret == 4)
    }
    
    func testCase2() throws {
        let nums = [4,5,6,7,0,1,2]
        let ret = sln33.search(nums ,3)
        
        XCTAssertTrue(ret == -1)
    }
    
    func testCase3() throws {
        let nums = [1]
        let ret = sln33.search(nums, 0)
        
        XCTAssertTrue(ret == -1)
    }
    
    func testCase4() throws {
        let nums = [1,3]
        let ret = sln33.search(nums, 3)
        
        XCTAssertTrue(ret == 1)
    }
    
    func testCase5() throws {
        let nums = [4,5,6,7,8,1,2,3]
        let ret = sln33.search(nums, 8)
        
        XCTAssertTrue(ret == 4)
    }
}

