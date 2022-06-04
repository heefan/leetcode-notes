//
//  LC02.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation
import XCTest

class LC02: XCTestCase {
    let sln02 = Solution02_rec()
    
    func testCase1() throws {
        let l1: ListNode? = LinkList([2,4,3]).head
        let l2: ListNode? = LinkList([5,6,4]).head
        
        let ret = sln02.addTwoNumbers(l1, l2)
        let retArray = ret?.toArray()
        
        XCTAssertTrue(retArray == [7,0,8])
    }
    
    func testCase2() throws {
        let l1: ListNode? = LinkList([0]).head
        let l2: ListNode? = LinkList([2]).head
        
        let ret = sln02.addTwoNumbers(l1, l2)
        let retArray = ret?.toArray()
        
        XCTAssertTrue(retArray == [2])
    }
    
    func testCase3() throws {
        let l1: ListNode? = LinkList([2,3,4]).head
        let l2: ListNode? = LinkList([5,7,6]).head
        
        let ret = sln02.addTwoNumbers(l1, l2)
        let retArray = ret?.toArray()
        
        XCTAssertTrue(retArray == [7,0,1,1])
    }
}
