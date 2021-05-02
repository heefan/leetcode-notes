#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <unordered_map> 

using namespace std;


class Solution {
    public:
        int countGoodRectangles(vector<vector<int>>& rectangles) {
            vector<int> maxLengths;
            for (int i = 0; i < rectangles.size(); ++i) {
                vector<int> each = rectangles[i];

                int maxLen = min(each[0], each[1]);
                maxLengths.push_back(maxLen);
            }

            for (auto it=maxLengths.begin(); it != maxLengths.end(); ++it) { 
                cout << *it << " ";
            }

            cout << endl;
            return numberOfMaxLength(maxLengths);
        }

        int numberOfMaxLength(vector<int>& lengths) {
            sort(lengths.begin(), lengths.end(), greater<int>());

            int maxValue = lengths[0];
            int ret = 0;
            for (auto it=lengths.begin(); it != lengths.end(); ++it) {
                if (*it == maxValue) {
                    ret += 1;
                } else {
                    break;
                }
            }
            return ret;
        }
};


int main() {
    vector<vector<int>> rectangles = {{5,8}, {3,9}, {5,12}, {16,5}};
    Solution s = Solution();
    cout << s.countGoodRectangles(rectangles) << endl;
    return 0;
}
