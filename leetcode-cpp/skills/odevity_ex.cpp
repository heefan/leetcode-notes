//
// Created by litian on 24/3/22.
//


#include <catch2/catch.hpp>
/**
 * 掌握：
 * 1. (num&1)==true is odd, false is even.
 */


bool isEven(int t) {
    // & 相当于乘法，如果结果为0, 说明t最后一位是0，必然为偶数。否则为奇数
    return (t&1) == 0;
}


TEST_CASE("Odevity") {
    SECTION("bit operation") {
        REQUIRE(isEven(2) == true);
        REQUIRE(isEven(4) == true);
        REQUIRE(isEven(7) == false);
    }

    SECTION("if statement") {
        int num = 10;

        if(num & 1) { // 奇数
            REQUIRE(isEven(num) == false);
        } else {  // 偶数
            REQUIRE(isEven(num) == true);
        }
    }
}
