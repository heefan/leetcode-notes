#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
    public:
        int balancedStringSplit(string s) {
            int count_L = 0;
            int count_R = 0;

            int result = 0;
            for(auto it=s.begin(); it != s.end(); it++) {
                switch(*it) {
                    case 'L':
                        count_L ++;
                        break;
                    case 'R':
                        count_R ++;
                        break;
                    default: 
                        break;
                }

                if(count_L == count_R) {
                    result ++;
                    count_L = 0;
                    count_R = 0;
                    continue;
                }
            }

            return result;
        }
};

int main() {
    class Solution s = Solution();
    cout << s.balancedStringSplit("LLRR") << endl;
    cout << s.balancedStringSplit("RLRRLLRLRL") << endl;
    cout << s.balancedStringSplit("RLLLLRRRLR") << endl;
    cout << s.balancedStringSplit("LLLLRRRR") << endl;
    cout << s.balancedStringSplit("RLRRRLLRLL") << endl;

    return 0;
}
