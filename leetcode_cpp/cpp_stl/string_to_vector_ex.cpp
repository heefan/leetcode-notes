//
// Created by LI Tian on 25/2/22.
//

#define CATCH_CONFIG_MAIN
#include <regex>  //C++11
#include <vector>
#include <iostream>
#include "catch2/catch.hpp"
#include "vector_helper.h"
#include <algorithm>

using namespace std;

// https://en.cppreference.com/w/cpp/regex/regex_token_iterator
// https://www.zhihu.com/question/36642771/answer/865135551  C++ 的 string 为什么不提供 split 函数？
// 分割字符串，并保存到vector中
// 我个人认为是最好记忆的方法，在算法使用中应该是足够了。
// 一般来说使用到这个方法的，基本都是复杂的题目。 在复杂的题目中，分割字符串只是工具，不是重点。
vector<string> split(const string& s, const string& regex_str) {
    regex re(regex_str);
    vector<string> list(sregex_token_iterator(s.begin(), s.end(), re, -1),
                        sregex_token_iterator());
    return list;
}

TEST_CASE("Split the string by delimiter") {
    SECTION("test on single delimiter") {
        string s = "hello world";
        vector<string> vec = split(s, " ");
        bool ret = isVectorSame(vec, {"hello", "world"});
        REQUIRE(ret==true);
    }

    SECTION("test on a string delimiter") {
        string s = "hello>>=world>>=!";
        vector<string> vec = split(s, ">>=");
        bool ret = isVectorSame(vec, {"hello", "world", "!"});
        REQUIRE(ret==true);
    }
}
