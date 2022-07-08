package backtrack;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution47 {

    public List<List<Integer>> answers = new LinkedList<>();
    boolean[] visit;
    LinkedList<Integer> permutation = new LinkedList<>();

    public List<List<Integer>> permute(int[] nums) {
        visit = new boolean[nums.length];
        Arrays.sort(nums);
        dfs(nums);
        return answers;
    }

    private void dfs(int[] nums) {
        if (permutation.size() == nums.length) {
            answers.add(new LinkedList<>(permutation));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visit[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]) continue;
                permutation.add(nums[i]);
                visit[i] = true;
                dfs(nums);
                permutation.removeLast();
                visit[i] = false;
            }
        }
    }
}
