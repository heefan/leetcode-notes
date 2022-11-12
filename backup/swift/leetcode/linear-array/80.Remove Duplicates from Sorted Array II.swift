//
//  80.Remove Duplicates from Sorted Array II.swift
//  leetcode
//
//  Created by litian on 4/6/22.
//

import Foundation

class Solution80 {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        if nums.count < 2 { return nums.count }  // Constraints 条件里有只有一个元素的情况
        
        var j = 1   // nums[0], nums[1] 一定合法，所以j=1
        
        // 小技巧：不需要罗列所有情况，我的目的是求j，所以只要知道j什么时候变化。
        for i in 2..<nums.count {
            if nums[i] != nums[j-1] {
                j = j+1
                nums[j] = nums[i]
            }
        }
        
        return j+1
    }
}

/*
 Given an integer array nums sorted in non-decreasing order,
 remove some duplicates in-place such that each unique element appears at most twice.
 The relative order of the elements should be kept the same.
 
 Since it is impossible to change the length of the array in some languages,
 you must instead have the result be placed in the first part of the array nums.
 More formally, if there are k elements after removing the duplicates,
 then the first k elements of nums should hold the final result.
 It does not matter what you leave beyond the first k elements.
 
 Return k after placing the final result in the first k slots of nums.
 
 Do not allocate extra space for another array.
 You must do this by modifying the input array in-place with O(1) extra memory.
 
 Example 1:
 Input: nums = [1,1,1,2,2,3]
 Output: 5, nums = [1,1,2,2,3,_]
 Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 It does not matter what you leave beyond the returned k (hence they are underscores).
 
 
 Example 2:
 Input: nums = [0,0,1,1,1,1,2,3,3]
 Output: 7, nums = [0,0,1,1,2,3,3,_,_]
 Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
 It does not matter what you leave beyond the returned k (hence they are underscores).
 
 Constraints:
 1 <= nums.length <= 3 * 104
 -104 <= nums[i] <= 104
 nums is sorted in non-decreasing order.
 
 
 评价：
 本题考察：双指针的思维方式 + 条件推断
 
 本题的难点：最多两个，如何将其转化成程序语言？ 难道左区最后的指针都要记录做多几个吗？
 
 [0,0,1,1,1,1,2,3,3]
 令 j 总是指合法区最后一个， i 进行遍历。
 起始：0,0，即，j=1， i=2， 因为前两个一定合法，无论是否重复
 
 when nums[i]=1, where i=2
    if nums[i] != nums[j]
        i++, j++   //valid
    
 when nums[i]=1, where i=3
    if nums[i] == nums[j]  && nums[i] != nums[j-1]   //valid
        i++, j++
  
 这里可以很快推断出，nums[i] 与 nums[j] nums[j-1]比较，
 因为是 non-descending, 所以很快可以推断出只需要和nums[j-1]比较即可。
 
 */
