//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution867 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};