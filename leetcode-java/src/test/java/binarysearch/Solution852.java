package binarysearch;

public class Solution852 {

    /* 852. Peak Index in a Mountain Array */
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0;
        int r = arr.length - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (m > 0 && arr[m] > arr[m - 1] && arr[m] > arr[m + 1])
                return m;
            if (arr[m] > arr[l] && arr[m] < arr[m + 1]) {
                l = m;
            }
            if (arr[m] > arr[r] && arr[m] < arr[m - 1]) {
                r = m;
            }
        }
        return -1;
    }
}
