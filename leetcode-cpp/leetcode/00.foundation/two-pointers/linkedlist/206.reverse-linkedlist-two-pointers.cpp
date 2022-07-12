//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution206_twoPointers {
public:

    // dry run:
    // pre   cur (head) -> node(cur->next)
    //                     copy of node: t
    //  pre   <--------------- node
    //       pre = cur
    //                     cur = t;
    // eventually, cur=nullptr, and pre will be the head.

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }

        return pre;
    }
};


// todo: add linked list support
TEST_CASE("206, reverse linked list") {
    SECTION("case1") {

    }
}