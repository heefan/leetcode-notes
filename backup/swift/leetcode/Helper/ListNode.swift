//
//  ListNode.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    
    public init() {
        self.val = 0;
        self.next = nil;
    }
    
    public init(_ val: Int) {
        self.val = val; self.next = nil;
    }
    
    public init(_ val: Int, _ next: ListNode?) {
        self.val = val;
        self.next = next;
    }
}

public class LinkList {
    var head: ListNode? = nil
    
    public init(_ nums: [Int]) {
        var curNode = head
        for i in 0..<nums.count {
            let node = ListNode(nums[i])
            if head == nil {
                head = node
                curNode = head
            } else {
                curNode?.next = node
                curNode = curNode?.next
            }
        }
    }
    
    func toArray(_ start: ListNode? = nil) -> [Int] {
        var node = start
        if start == nil {
            node = head
        }
        
        var nums = [Int]()
        while node != nil {
            nums.append(node!.val)
            node = node?.next
        }
     
        return nums
    }
}

extension ListNode {
    func toArray() -> [Int] {
        var node: ListNode? = self
        var nums = [Int]()
        while node != nil {
            nums.append(node!.val)
            node = node?.next
        }
        return nums
    }
}

