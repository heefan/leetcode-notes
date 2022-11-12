package binarytree;

public class Solution938 {

    /* 938. Sum of binary search tree */
    public int rangeSumBST(TreeNode root, int low, int high) {

        if (root == null)
            return 0;
        while (root != null) {
            if (root.val >= low && root.val <= high) {

                return root.val + rangeSumBST(root.right, low, high) + rangeSumBST(root.left, low, high);

            } else if (root.val < low) {
                root = root.right;
            } else {
                root = root.left;
            }

        }

        return 0;
    }
}
