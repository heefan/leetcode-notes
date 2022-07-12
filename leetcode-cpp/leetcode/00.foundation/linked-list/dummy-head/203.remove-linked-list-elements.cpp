//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution203 {
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;

        while(cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};

//todo: add test