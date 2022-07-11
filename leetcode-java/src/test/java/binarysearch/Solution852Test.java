package binarysearch;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class Solution852Test {
    Solution852 sln;

    @BeforeEach
    void setUp() {
        sln = new Solution852();
    }

    @Test
    void search() {
        int[] nums = { 5, 6, 9, 7, 3, 2, 0 };
        int ans = sln.peakIndexInMountainArray(nums);
        Assertions.assertEquals(ans, 2);

        int[] nums2 = { 1, 2, 3, 5, 9, 10, 4, 2, 1 };
        int ans2 = sln.peakIndexInMountainArray(nums2);
        Assertions.assertEquals(ans2, 5);
    }
}
