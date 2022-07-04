//
// Created by litian on 28/6/22.
//

#include "common_inc.h"

class Solution22 {
public:
    vector<string> ans;
    stack<char> stk;

    vector<string> generateParenthesis(int n) {
        string path;
        dfs(n, 0, 0, path);
        return ans;
    }

private:
    void dfs(int n, int openN, int closeN, string & path) {
        if(openN == closeN and openN == n) {
            ans.push_back(path);
            return;
        }

        if (openN < n) {
            path.append("(");
            dfs(n, openN+1, closeN, path);
            path.pop_back();
        }

        if (closeN < openN) {
            path.append(")");
            dfs(n, openN, closeN+1, path);
            path.pop_back();
        }

    }
};


TEST_CASE("Solution22") {
    Solution22 sln;

    SECTION("case1") {
        vector<string> ans = sln.generateParenthesis(3);
        vector<string> expect = {"((()))","(()())","(())()","()(())","()()()"};

        REQUIRE(isVectorSame(expect, ans));
    }

    SECTION("case2") {
        vector<string> ans = sln.generateParenthesis(1);
        vector<string> expect = {"()"};

        REQUIRE(isVectorSame(expect, ans));

    }
}