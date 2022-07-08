package binarysearch;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class Solution704Test {
    Solution704 sln;

    @BeforeEach
    void setUp() {
        sln = new Solution704();
    }

    @Test
    void search() {
        int[] nums = {1, 2, 3};
        int ans = sln.search(nums, 2);
        Assertions.assertEquals(ans, 1);

        int[] nums2 = {1, 2, 3, 5, 9, 10};
        int ans2 = sln.search(nums2, 9);
        Assertions.assertEquals(ans2, 4);
    }
}
