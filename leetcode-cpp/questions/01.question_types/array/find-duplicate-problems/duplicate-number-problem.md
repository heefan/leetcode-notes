# Find Duplicate Numbers in an Array

## Solution: 
1. Hash set
   1. iterate the array and put the element into set, if new element exist, this is the answer
   2. TC: O(n), SC: O(n)
2. Sort
   1. Sort the array, and iterate the array. If nums[i-1] == nums[i], it's the answer
   2. TC: O(Nlog(N)),  SC: O(1)
3. In-place hash (modify nums array)
   1. base on the condition, 1~n, if(nums[i] != i+1), then swap(nums[i], nums[nums[i]-1])
   2. TC: O(N), SC: O(1)
4. Binary search (not modify nums array)
   1. base on the condition, 1~n, apply pigeonhole principle
   2. TC: O(Nlg(N)), SC: O(1)
   3. [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
* restriction: no modifying and SC O(1)
5. Fast-slow pointers  (not modify nums array)
   1. TC: O(N), SC: O(1)
   2. [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
* restriction: no modifying and SC O(1)




