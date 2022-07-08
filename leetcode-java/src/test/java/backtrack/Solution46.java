package backtrack;

import java.util.ArrayList;
import java.util.List;

public class Solution46 {

    public List<List<Integer>> answers = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {

        boolean[] visit = new boolean[nums.length];
        List<Integer> permutation = new ArrayList<>();
        dfs(nums, permutation, visit);
        return answers;
    }

    private void dfs(int[] nums, List<Integer> permutation, boolean[] visit) {
        if (permutation.size() == nums.length) {
            answers.add(new ArrayList<>(permutation));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visit[i]) {
                permutation.add(nums[i]);
                visit[i] = true;
                dfs(nums, permutation, visit);
                permutation.remove(permutation.get(permutation.size() -1));
                visit[i] = false;
            }
        }
    }
}
