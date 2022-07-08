package backtrack;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution47Test {
    Solution47 sln;

    @BeforeEach
    void setUp() {
        sln = new Solution47();
    }

    @Test
    void permute() {
        int[] nums = {2,3,1,2};
        List<List<Integer>> ans = sln.permute(nums);
        List<List<Integer>> expect = new ArrayList<>();
        expect.add(Arrays.asList(1,2,2,3));
        expect.add(Arrays.asList(1,2,3,2));
        expect.add(Arrays.asList(1,3,2,2));
        expect.add(Arrays.asList(2,1,2,3));
        expect.add(Arrays.asList(2,1,3,2));
        expect.add(Arrays.asList(2,2,1,3));
        expect.add(Arrays.asList(2,2,3,1));
        expect.add(Arrays.asList(2,3,1,2));
        expect.add(Arrays.asList(2,3,2,1));
        expect.add(Arrays.asList(3,1,2,2));
        expect.add(Arrays.asList(3,2,1,2));
        expect.add(Arrays.asList(3,2,2,1));
        Assertions.assertEquals(ans, expect );

        for(List<Integer> perm:ans) {
            System.out.println(perm);
        }
    }


}
