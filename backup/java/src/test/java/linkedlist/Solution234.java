package linkedlist;

public class Solution234 {

    /*
     * 234. Slow/fast pointer to find middle of linked list And reverse middle
     * linked list
     */

    public boolean isPalindrome(ListNode head) {
        ListNode mid = middle(head);
        ListNode reversed = reverse(mid);

        while (reversed != null) {

            if (head.val != reversed.val)
                return false;
            head = head.next;
            reversed = reversed.next;
        }

        return true;
    }

    private ListNode middle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    private ListNode reverse(ListNode head) {

        ListNode prev = null;
        ListNode cur = head;

        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
}
