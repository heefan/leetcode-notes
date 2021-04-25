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
		vector<int> minSubsequence(vector<int>& nums){
			sort(nums.begin(), nums.end(), greater<int>());

			printVector(nums);
			
			vector<int> lArray = { nums[0] };
			int lSum = nums[0];
			for (int i = 0, j = 1; i < nums.size(); ++i) {
			    int rSum = accumulate(nums.begin()+j, nums.end(), 0); 
				if (lSum > rSum) {
					break;
				} else {
				    lArray.push_back(nums[j]);
					lSum += nums[j];
					j++;
				}
			}


			return lArray;

		}
};


int main() {
	Solution s = Solution();
	vector<int> test1 = {4, 3, 10, 9, 8};
	vector<int> ret = s.minSubsequence(test1);
	printVector(ret);

	vector<int> test2 = {4, 4, 7, 6, 7};
	vector<int> ret2 = s.minSubsequence(test2);
	printVector(ret2);

	cout << endl;

	return 0;
}

