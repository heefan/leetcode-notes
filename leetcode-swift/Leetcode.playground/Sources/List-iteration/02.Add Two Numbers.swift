import Foundation

class Solution02 {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var l1: ListNode? = l1
        var l2: ListNode? = l2
        var result: ListNode? = ListNode(0)
        let head = result
        var carry = 0

        while l1 != nil || l2 != nil || carry > 0 {
            let op1 = l1?.val ?? 0
            let op2 = l2?.val ?? 0
            let sum = op1 + op2 + carry

            let value = sum % 10
            carry = sum / 10

            result?.next = ListNode(value)
            result = result?.next
            l1 = l1?.next
            l2 = l2?.next
        }

        return head?.next
    }
}
