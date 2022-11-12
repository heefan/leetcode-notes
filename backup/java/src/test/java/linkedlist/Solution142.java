package linkedlist;

public class Solution142 {

    /*
     * 142. Find the node where the cycle begin
     */
    public ListNode detectCycle(ListNode head) {

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                break;
        }

        if (fast == null || fast.next == null)
            return -1;

        while (head != slow) {
            head = head.next;
            slow = slow.next;
        }

        return head;
    }
}
