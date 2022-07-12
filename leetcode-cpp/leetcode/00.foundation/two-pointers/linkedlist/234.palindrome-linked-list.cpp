//
// Created by litian on 12/7/22.
//

#include "common_inc.h"

class Solution234 {
public:
    // requirement: SC:O(1), TC:O(n)
    // dry run:
    // 1 - 2 - 2 - 1
    // revert  head-middle and compare with middle+1 to end
    // if same, it is palindrome linked list

    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        ListNode* mid = middleNode(head);    // O(n)
        ListNode* mid2end = reverseList(mid);

        while(mid2end) {
            if(cur->val != mid2end->val) {
                return false;
            }
            cur = cur->next;
            mid2end = mid2end->next;
        }
        return true;
    }

private:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

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