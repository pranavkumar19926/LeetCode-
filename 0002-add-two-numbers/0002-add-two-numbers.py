class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        temp1 = l1
        temp2 = l2

        ans = ListNode(0)
        test = ans
        carry = 0

        while temp1 is not None and temp2 is not None:

            valu = temp1.val + temp2.val + carry

            if valu >= 10:
                carry = valu // 10
                valu = valu % 10
            else:
                carry = 0

            EY = ListNode(valu)
            test.next = EY
            test = test.next

            temp1 = temp1.next
            temp2 = temp2.next

        while temp1 is not None:

            valu = temp1.val + carry

            if valu >= 10:
                carry = valu // 10
                valu = valu % 10
            else:
                carry = 0

            EY = ListNode(valu)
            test.next = EY
            test = test.next

            temp1 = temp1.next

        while temp2 is not None:

            valu = temp2.val + carry

            if valu >= 10:
                carry = valu // 10
                valu = valu % 10
            else:
                carry = 0

            EY = ListNode(valu)
            test.next = EY
            test = test.next

            temp2 = temp2.next

        if carry > 0:
            test.next = ListNode(carry)

        return ans.next