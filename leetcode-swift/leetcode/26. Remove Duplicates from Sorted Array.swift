//
//  26.Remove Duplicates from Sorted Array.swift
//  leetcode
//
//  Created by litian on 3/6/22.
//

import Foundation

public class Solution26 {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var j = 0
        
        for i in 1..<nums.count {
            if nums[j] != nums[i] {
                j += 1
                nums[j] = nums[i]
            }
        }
        
        return j + 1
    }
}


/*
 1. 不使用额外空间
 2. 1 <= nums.length <= 3 * 10^4
 
 Example 1:
 
 Input: nums = [1,1,2]
 Output: 2, nums = [1,2,_]
 Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
 It does not matter what you leave beyond the returned k (hence they are underscores).
 
 
 Example 2:
 Input: nums = [0,0,1,1,1,2,2,3,3,4]
 Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
 It does not matter what you leave beyond the returned k (hence they are underscores).

 
 */
