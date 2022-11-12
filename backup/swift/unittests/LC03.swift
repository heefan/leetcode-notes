//
//  LC03.swift
//  leetcode
//
//  Created by litian on 5/6/22.
//

import Foundation
import XCTest

class LC03: XCTestCase {
    let sln03 = Solution03()
    
    func testCase1() throws {
        let s = "abcabcbb"
        let ret = sln03.lengthOfLongestSubstring(s)
        
        XCTAssertTrue(ret == 3)
    }
    
    func testCase2() throws {
        let s = "bbbbb"
        let ret = sln03.lengthOfLongestSubstring(s)
        
        XCTAssertTrue(ret == 1)
    }
    
    func testCase3() throws {
        let s = "pwwkew"
        let ret = sln03.lengthOfLongestSubstring(s)
        
        XCTAssertTrue(ret == 3)
    }
    
}
