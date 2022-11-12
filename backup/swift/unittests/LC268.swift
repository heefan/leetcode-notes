//
//  LC268.swift
//  leetcode
//
//  Created by litian on 12/6/22.
//

import Foundation


import XCTest

class LC268: XCTestCase {
    let sln = Solution268()
    
    func testCase1() throws {
        let nums = [9,6,4,2,3,5,7,0,1]
        
        let ans = sln.missingNumber(nums)
        XCTAssertTrue(ans == 8)
    }
    
}
