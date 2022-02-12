import Foundation

/// PreSum 前缀和
/// 性质： 给出int数组nums[0...n], 求 nums[i...j]的和。
///

/// Given
let nums = [1,2,3,4,5]
let sln = Solution()
let case1 = sln.getSubArraySum(nums, i:1, j:3)
assert(case1 == 9)

/// 解答： the sum of nums[2...4]
class Solution {
    func getSubArraySum(_ nums: [Int], i: Int, j: Int) -> Int {
        var presum = [Int](repeating: 0, count: nums.count+1)
        presum[0] = 0;
        
        for i in 0..<nums.count {
            presum[i+1] = presum[i] + nums[i]
        }

        return presum[j+1]-presum[i]
    }
}

///
