package binarysearch;

public class Solution744 {

    // red blue method
    public char nextGreatestLetter(char[] letters, char target) {
        int l = -1;
        int r = letters.length;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (letters[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }

        return r >= letters.length ? letters[0]: letters[r];
    }
}
