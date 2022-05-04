import Foundation

class Solution26 {
    func mergeTwoLists(_ list1: ListNode?, _ list2: ListNode?) -> ListNode? {

        var l1 = list1
        var l2 = list2
        let dummy = ListNode(-1)
        var curNode = dummy

        while l1 != nil && l2 != nil {
            if l1!.val <= l2!.val {
                curNode.next = l1
                l1 = l1!.next
            } else {
                curNode.next = l2
                l2 = l2!.next
            }

            curNode = curNode.next!
        }

        curNode.next = (l1 == nil) ? l2 : l1

        return dummy.next
    }
}
