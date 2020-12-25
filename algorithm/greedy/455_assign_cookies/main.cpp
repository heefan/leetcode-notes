#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());

			int count = 0;
			vector<int>::iterator gIt = g.begin();
			vector<int>::iterator sIt = s.begin();

	//		for(; gIt != g.end(); gIt++) {
	//			cout << *gIt << " ";
	//		}
	//		cout << endl;

	//		for(; sIt != s.end(); sIt++) {
	//			cout << *sIt << " ";
	//		}
	//		cout << endl;

			while(1) {
				if (gIt == g.end()) break;
				if (sIt == s.end()) break;

				if (*sIt >= *gIt) {
					cout << *sIt << "," << *gIt << endl;
					count ++;
					sIt++;
					gIt++;
				} else {
					sIt++;
				} 		
			}

			return count;
		}
};

int main() {
	class Solution s = Solution();
	vector<int> greedyIndex = {10, 9, 8, 7};
	vector<int> sizeOfCookies = {5, 6, 7, 8};
	int output = s.findContentChildren(greedyIndex, sizeOfCookies);

	cout << "output: " << output << endl;

	return 0;

}
