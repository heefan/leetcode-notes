//
//  268. Missing Number.swift
//  leetcode
//
//  Created by litian on 12/6/22.
//

import Foundation

class Solution268 {
    func missingNumber(_ nums: [Int]) -> Int {
        var nums = nums
        let n = nums.count
        
        for i in 0..<n {
            if nums[i] != i && nums[i] < n {
                nums.swapAt(nums[i], i)
            }
            print("\(i): \(nums)")
        }
        
        
        for i in 0..<nums.count {
            if nums[i] != i {
                return i
            }
        }
        
        return n
    }
    
};
