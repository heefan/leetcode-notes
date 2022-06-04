//
//  33.Search in Rotated Sorted Array.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation

class Solution33 {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var left = 0, right = nums.count-1
        
        while left <= right {
            let mid = left + (right - left) / 2
            if nums[mid] == target { return mid }
            
            if nums[0] <= nums[mid] {  //左区是有序的
                if nums[0] <= target && target < nums[mid] {
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            } else { //右区是有序的
                if (nums[mid] < target && target <= nums.last!) {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
        }
        
        return -1
    }
}

// 强调：
// 旋转数组的性质：
// 旋转后，一定一个区是排序的，一个区不是排序的，解决排序的，更新left,right去乱序。

// 注：
// 本地历史提交15次，仅仅2次通过。大部分我都是分情况讨论，但这样往往不能通过所有的情况。
// 如果要问如何才能现场观察出rotated array性质？
// 滚一边做题去。

/*
 There is an integer array nums sorted in ascending order (with distinct values).
 
 Prior to being passed to your function, nums is possibly rotated at an unknown pivot index
 k (1 <= k < nums.length) such that the resulting array is
 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 
 Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 
 You must write an algorithm with O(log n) runtime complexity.
 
 Example 1:
 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 
 Example 2:
 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1
 
 Example 3:
 Input: nums = [1], target = 0
 Output: -1
 
 Constraints:
 1 <= nums.length <= 5000
 -104 <= nums[i] <= 104
 All values of nums are unique.
 nums is an ascending array that is possibly rotated.
 -104 <= target <= 104
 */
