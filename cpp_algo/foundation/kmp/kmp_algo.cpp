//
// Created by litian on 11/3/22.
//

#include "catch2/catch.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "vector_helper.h"

using namespace std;

vector<int> getPrefixTable(string & pattern) {
    int n = pattern.size();
    vector<int> pi(n, 0);
    int i = 1;  // i表示吃进的最新元素，第0个元素一定是0
    int len = 0;  //最长的公共前后缀子串长度

    while(i<n) {
        if(pattern[i] == pattern[len]) {  //核心: 匹配时
            len++;
            pi[i] = len;
            i++;
        }
        else {
            if(len>0) { // 核心：不匹配时
                len = pi[len-1];
            } else {  // 特例，当len==0时，
                pi[i] = len;
                i++;
            }
        }
    }

    return pi;
}

void shift(vector<int>& pi) {
    int n = pi.size();
    for(int i=n; i>0; i--) {
        pi[i] = pi[i-1];
    }
    pi[0] = -1;
}

void kmp(string text, string pattern) {
    int n = pattern.length();
    int m = text.length();
    vector<int> pi = getPrefixTable(pattern);
    shift(pi);

    int i = 0;
    int j = 0;
    while(i<m) {
        if(j==n-1 and text[i] == pattern[j]) {
            cout << "found pattern at " << i-j << endl;
            j = pi[j];
        }

        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = pi[j];
            if(j==-1) {
                i++;
                j++;
            }
        }
    }
}

TEST_CASE("KMP Algorithm") {
    SECTION("Give a string, find out prefix table") {
        string pattern = "mississippi";
        vector<int> pi = getPrefixTable(pattern);
//        REQUIRE(isVectorSame(pi, {0,0,1,2,0,1,2,3,1}) == true);
    }

  //  SECTION("Shift") {
  //      string pattern = "ababc";
  //      vector<int> pi = getPrefixTable(pattern);
  //      shift(pi);
  //      REQUIRE(isVectorSame(pi, {-1,0,0,1,2,0,1,2,3}) == true);
  //  }

  //  SECTION("KMP") {
  //      string pattern = "ababcabaa";
  //      string text = "abababcabaabababab";
  //      kmp(text, pattern);
    }
}