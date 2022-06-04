//
//  LinkListSpec.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation
import XCTest

class LinkListSpec: XCTestCase {
    
    func testCase1() throws {
        let nums = [1,2,3]
        let linkList = LinkList(nums)
        
        XCTAssertTrue(linkList.toArray() == [1,2,3])
    }
}
