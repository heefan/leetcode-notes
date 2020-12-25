#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
	public:
		int candy(vector<int>& ratings) {
			int size = ratings.size();
			if (size < 2) {
				return size;
			}

			vector<int> num(size, 1);

			for (int i = 1; i < size; ++i) {
				if (ratings[i] > ratings[i-1]) {
					num[i] = num[i-1] + 1;
				}
			}

			for (int i = 0; i < size - 1; i++) {
				cout << num[i] << " ";
			}

			cout << endl;

			for (int i = size-1; i > 0; i--) {
				if (ratings[i] < ratings[i-1]) {
					num[i-1] = max(num[i-1], num[i] + 1);	
				}
			}

			for (int i = 0; i < size - 1; i++) {
				cout << num[i] << " ";
			}

			cout << endl;

			return  accumulate(num.begin(), num.end(), 0);
		}
};


int main() {
	vector<int> ratings = {1, 0, 2, 5, 4};

	Solution sln = Solution();
	cout << sln.candy(ratings) << endl;
	
	return 0;
}
