import sys

from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        def findMinNodeIndex(ptrs:List[ListNode])->int:

            index = -1
            minVal = sys.maxsize

            for i in range(len(ptrs)):
                if ptrs[i] != None:
                    print("DEBUG: ", ptrs[i].val, minVal)
                    if ptrs[i].val < minVal:
                        minVal = ptrs[i].val
                        index = i

            return index

        dummy = ListNode(0)
        tmp = dummy

        listNodes = [None] * len(lists)

        for i in range(len(lists)):
            listNodes[i] = lists[i]

        print(listNodes)
        # print("listNodes: ", listNodes)
        while True:
            i = findMinNodeIndex(listNodes)
            # print("i: ", i)
            # stop in case no more nodes to add
            if i == -1:
                break

            node = listNodes[i]
            listNodes[i] = node.next

            tmp.next = node
            tmp = tmp.next

        return dummy.next

lists = [ListNode(1,ListNode(4, ListNode(5))),ListNode(1,ListNode(3,ListNode(4))),ListNode(2,ListNode(6))]

sol = Solution()
res = sol.mergeKLists(lists)
while res:
    print(res.val)
    res = res.next
