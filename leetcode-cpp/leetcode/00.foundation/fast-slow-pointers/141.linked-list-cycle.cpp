//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution141 {
    bool hasCycle(ListNode *head) {
        if(!head) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }

        return false;
    }
};

//todo: add test for linked list