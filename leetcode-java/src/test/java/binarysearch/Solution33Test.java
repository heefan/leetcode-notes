package binarysearch;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class Solution33Test {
    Solution33 sln;

    @BeforeEach
    void setUp() {
        sln = new Solution33();
    }

    @Test
    void search() {
        int[] nums = { 4, 5, 6, 7, 9, 0, 1, 2 };
        int ans = sln.search(nums, 7);
        Assertions.assertEquals(ans, 3);

        int[] nums2 = { 22, 29, 35, 44, 99, 4, 10, 14 };
        int ans2 = sln.search(nums2, 10);
        Assertions.assertEquals(ans2, 6);
    }
}
