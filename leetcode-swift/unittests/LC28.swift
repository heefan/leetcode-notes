//
//  28_spec.swift
//  unittests
//
//  Created by litian on 4/6/22.
//

import Foundation
import XCTest

class LC80: XCTestCase {
    let sln80 = Solution80()
    
    func testCase1() throws {
        var nums = [1,1,1,2,2,3]
        let ret = sln80.removeDuplicates(&nums)
        
        XCTAssertTrue(ret == 5)  //[1,1,2,2,3,_]
        XCTAssertTrue(nums[0...ret-1] == [1,1,2,2,3])
    }
    
    func testCase2() throws {
        var nums = [0,0,1,1,1,1,2,3,3]
        let ret = sln80.removeDuplicates(&nums)
        
        XCTAssertTrue(ret == 7)
        XCTAssertTrue(nums[0...ret-1] == [0,0,1,1,2,3,3])
    }
    
    func testCase3() throws {
        var nums = [1]
        let ret = sln80.removeDuplicates(&nums)
        
        XCTAssertTrue(ret == 1)
        XCTAssertTrue(nums[0...ret-1] == [1])
    }
}

