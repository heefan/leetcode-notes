//
// Created by LI Tian on 25/2/22.
//

#include "catch2/catch.hpp"
#include <string>

using namespace  std;

TEST_CASE("int to string and string to in") {
    SECTION("int to string") {
        int a = 101;

        REQUIRE(to_string(a) == "101");  //c++11
    }

    SECTION("string to int") {
        string a = "101";
        REQUIRE(stoi(a) == 101);  //c++11
    }
}