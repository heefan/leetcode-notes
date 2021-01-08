#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
	public:
		int eraseOverlapIntervals(vector<vector<int>>& intervals) {
			if (intervals.size() == 0) return 0;

			int size = intervals.size();
			int amountRemoved = 0;

			sort(intervals.begin(), 
				 intervals.end(),
				 [](const vector<int>&a, const vector<int>&b) -> bool {
					return a[1] <= b[1];
				});

			for(auto each: intervals) {
				cout << "(" << each[0] << "," << each[1] << ") ";  
			}

			int previousEnd = intervals[0][1];
			for (int i = 1; i < size; i++) {
				// if the current interval's start is less than the previous interval's end, overlap
				if (intervals[i][0] < previousEnd) {
					amountRemoved++;
				} 
				else {
					// if there is no overlap, update previousEnd
					previousEnd = intervals[i][1]; 
				}
			}

			return amountRemoved;
		}
};


int main() {

	vector<vector<int>> A = {{1, 2}, {3,4}, {2,3}, {1,3}};

	Solution sln = Solution();
	cout << sln.eraseOverlapIntervals(A) << endl;

	return 0;
}
