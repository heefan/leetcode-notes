# 求最长子序列问题 
## Longest Increasing Subsequence (LIS)

## 思考方向： DP
子序列是不连续的，所以用双指针和滑动窗口都不合适，因为他们都是解决连续问题的。
所以考虑用DP方法。

### 弄清楚 DP[i] 在连续与不连续的含义. 
这是一个有后效性问题。所以要固定`i`。 但是一定要包含nums[i]。 
这里包含的意思是, 搜索中包含nums[i], 并且结果也要包含nums[i].

与连续性问题不同的是，dp[i]的含义不同。
连续的: dp[i] 是以i为结尾的连续子串的,最长子序列. 
非连续的:dp[i] 是以i为结尾的连续子串的,最长子序列. 强调包含nums[i]

连续的,不强调,因为 [0,1,2,3,0] 和 [0,1,2,3] 结果是一样的.
不连续的,要强调, 因为 降序的时候, dp[i] 与 dp[i-1] 没有关系, 而是1. 

比如: 当前状态[0,1,3], 下一个是2
[0,1,3,2] 包换了2在内的,最长的连续子串是[0,1,3]
[0,1,3,2] 包含了2在内的,不连续的子串是[2]本身. 因为[0,1,3]是最长的,但是不包含2这个条件!

所以在连续的子数组中, dp[3]=3, 而在非连续中,dp[3]=1

### 状态转移方程 (不连续)
dp[i]进来时并不知道和dp[0..<i]的关系,所以要回头遍历, 一个个组合再去更新dp表. 

[0,1,3],  2
要回头遍历, 只不过说dp已经记录了前状态, 可以节约一些时间. 这是DP的初衷起始.
当j=0时, 满足 nums[0] < nums[2] 升序情况, dp[0] 已经计算过了, 所以可以直接dp[0]+1
当j=1时, 满足 nums[1] < nums[2] 升序情况, dp[1] 已经计算过了, 所以可以直接dp[1]+1
...
不满足条件时候,就是自己本身,为 dp[i] = 1
最后从中取出最大值. 就是满足升序状态时, dp[i] = max(dp[0..<i]+1)

范例： [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

## 练习顺序
[300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
* 评价: 必须会, 这是LIS的最基本题型.
[744. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)
[题解](https://leetcode.cn/problems/number-of-longest-increasing-subsequence/solution/gong-shui-san-xie-lis-de-fang-an-shu-wen-obuz/)
* 评价: 

