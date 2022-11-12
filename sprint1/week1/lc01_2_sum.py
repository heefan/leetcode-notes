from typing import List
class Solution01:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, v in enumerate(nums):
            if target - v not in d:
                d[v] = i
            else:
                return [d[target-v], i]
            -1


def test_1():
    sln = Solution01()
    expect = [0,1]
    ans = sln.twoSum([2, 7, 11, 15], 9)
    assert(ans == expect)


def test_2():
    sln = Solution01()
    expect = [1, 2]
    ans = sln.twoSum([3, 2, 4], 6)
    assert(ans == expect)


def test_3():
    sln = Solution01()
    expect = [0, 1]
    ans = sln.twoSum([3, 3], 6)
    assert (ans == expect)

