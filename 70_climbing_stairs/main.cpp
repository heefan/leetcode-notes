#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
    public:
        int uniquePaths(int m, int n) {
            if(m<1) return 0;
            if(n<1) return 0;

            int** dp = new int*[m];
            for(int i = 0; i < m; ++i)
                  dp[i] = new int[n];

            dp[0][0] = 0;
            dp[0][1] = 1;
            dp[1][0] = 1;

            for(int i = 1; i<m; i++) {
                for(int j = 1; j<n; j++) {
                    if(i-1 == 0) {
                        dp[i-1][j] = 1;
                    }

                    if(j-1 == 0) {
                        dp[i][j-1] = 1;
                    }

                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }


            return dp[m-1][n-1];

        }

};


int main() {
    Solution s = Solution();
    cout << s.uniquePaths(7,3) << endl;

    return 0;
}

