//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution83 {
public:
    ListNode* deleteDuplicates1(ListNode* head) {
        ListNode* dummy = new ListNode(-101, head);
        ListNode* cur = dummy;

        while(cur->next) {
            if (cur->next->val == cur->next->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }


        return dummy->next;
    }


    ListNode* deleteDuplicates2(ListNode* head) {
        ListNode* cur = head;

        while(cur->next) {
            if (cur->next->val == cur->next->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }


        return head;
    }
};