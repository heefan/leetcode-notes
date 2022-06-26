import com.sun.java.swing.plaf.windows.WindowsTextAreaUI;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class Solution46Test {
    Solution46 sln;

    @BeforeEach
    void setUp() {
        sln = new Solution46();
    }

    @Test
    void permute() {
        List<Integer> nums = Arrays.asList(1,2,3);
        List<List<Integer>> ans = sln.permute(nums);
        List<List<Integer>> expect = Arrays.asList()



    }
}