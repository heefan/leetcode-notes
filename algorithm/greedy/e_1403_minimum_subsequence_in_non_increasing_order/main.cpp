#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
	public:
		vector<int> minSubsequence(vector<int>& nums) {
			sort(nums.begin(), nums.end(), greater<int>());
			for(int i=0; i < nums.size(); ++i) {
				cout << nums[i] << " ";
			}
			cout << endl;


			return nums;

		}
};


int main() {
	Solution s = Solution();
	vector<int> nums = {4, 3, 10, 9, 8};
	vector<int> ret = s.minSubsequence(nums);

	for(int i=0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}
