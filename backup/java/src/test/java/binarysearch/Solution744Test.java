package binarysearch;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class Solution744Test {
    Solution744 sln;

    @BeforeEach
    void setUp() {
        sln = new Solution744();
    }

    @Test
    void nextGreatestLetter() {
        char[] nums = "klnop".toCharArray();
        char ch = 'z';
        int ans = sln.nextGreatestLetter(nums, ch);
        char expect = 'k';
        Assertions.assertEquals(ans, expect);

        nums = "adfkmosy".toCharArray();
        ch = 'n';
        ans = sln.nextGreatestLetter(nums, ch);
        expect = 'o';
        Assertions.assertEquals(ans, expect);
    }
}
