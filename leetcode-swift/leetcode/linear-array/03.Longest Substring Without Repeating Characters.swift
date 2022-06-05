//
//  File.swift
//  leetcode
//
//  Created by litian on 5/6/22.
//

import Foundation
import XCTest


class Solution03 {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.count <= 1 { return s.count }
        
        let array = Array(s)
        var set: Set = [s.first!]
        var left = 0
        var ret = 0
        
        for i in 1..<array.count {
            while set.contains(array[i]) {
                let leftChar = array[left]
                set.remove(leftChar)
                left = left + 1
            }
            
            set.insert(array[i])
            ret = max(ret, i - left + 1)
        }
        
        return ret
    }
}

// 超时，不要使用 string来操作。

//class Solution03 {
//    func lengthOfLongestSubstring(_ s: String) -> Int {
//        if s.count <= 1 { return s.count }
//
//        var set: Set = [s.first!]
//        var left = 0
//        var ret = 0
//
//        for i in 1..<s.count {
//            let char = s[s.index(s.startIndex, offsetBy: i)]
//            while set.contains(char) {
//                let leftChar = s[s.index(s.startIndex, offsetBy: left)]
//                set.remove(leftChar)
//                left = left + 1
//            }
//
//            set.insert(char)
//            ret = max(ret, i - left + 1)
//        }
//
//        return ret
//    }
//}

/*
 
 Example 1:
 Input: s = "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 
 Example 2:
 Input: s = "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 
 Example 3:
 Input: s = "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 
 Constraints:
 0 <= s.length <= 5 * 104
 s consists of English letters, digits, symbols and spaces.
 
 */
