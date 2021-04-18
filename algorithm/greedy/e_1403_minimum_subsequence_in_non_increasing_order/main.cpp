#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
	cout << endl;
}

class Solution {
	public:
		vector<int> minSubsequence(vector<int>& nums) {
			sort(nums.begin(), nums.end(), greater<int>());

			printVector(nums);



			return nums;

		}
};


int main() {
	Solution s = Solution();
	vector<int> nums = {4, 3, 10, 9, 8};
	vector<int> ret = s.minSubsequence(nums);

	printVector(ret);

	cout << endl;

	return 0;
}

