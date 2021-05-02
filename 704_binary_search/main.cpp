#include <iostream>
#include <vector>
#include "helper.h"

using namespace std;


class Solution {
	public:
		int search(vector<int>& nums, int target) {

			int rightIndex = nums.size() - 1;
			int leftIndex = 0;
			int midIndex = (rightIndex - leftIndex) / 2;

			while(1) {
				int midValue = nums[midIndex];
				if (target == midValue) { return midIndex; }
				if (leftIndex >= rightIndex) { return -1; }

				if (target > midValue) { 
					leftIndex = midIndex + 1;
					midIndex = (rightIndex + leftIndex) / 2;
				}

				if (target < midValue) {
					rightIndex = midIndex;
					midIndex = (rightIndex - leftIndex) /  2;
				}				
			}


			return -1;

		}
};


int main() {
	Solution s = Solution();
	vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
	cout << s.search(nums1, 9) << endl;
	cout << s.search(nums1, -1) << endl;
	cout << s.search(nums1, 0) << endl;
	cout << s.search(nums1, 100) << endl;
	cout << s.search(nums1, 2) << endl;

	vector<int> nums2 = {2, 5};
	cout << s.search(nums2, 5) << endl;
	cout << s.search(nums2, 2) << endl;

	return 0;
}
