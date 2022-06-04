//
//  2.Add Two Numbers.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation

public class Solution02_rec {
    var carry: Int = 0
    
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil && l2 == nil {
            if carry > 0 {
                let node = ListNode(carry)
                carry = 0
                return node
            }
            return nil
        }
        
        let op1 = l1?.val ?? 0
        let op2 = l2?.val ?? 0
        
        let sum = op1 + op2 + carry
        carry = sum / 10
        
        let head = ListNode(sum % 10)
        let node = addTwoNumbers(l1?.next, l2?.next)
        head.next = node
        
        return head
    }
}

public class Solution02_iter {
    
}
