//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution142 {
    ListNode *detectCycle(ListNode *head) {
        // dry run. 2022.07.12
        //  step1: find out the meet point, SC: O(n), O(1)
        //  step2: start from head and meet point, if meet again, that is the node required.
        //      Otherwise, it will not have the node.
        // Total: TC: O(N), SC: O(1)

        if (!head) return head;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (fast == nullptr or fast->next == nullptr) return nullptr;

        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }

        return slow;
    }
};