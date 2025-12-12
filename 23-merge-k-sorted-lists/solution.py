import sys
import heapq
from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        dummy = ListNode(0)
        tmp = dummy

        listNodesHeap = []

        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(listNodesHeap, (lists[i].val, i, lists[i]))

        while listNodesHeap:
            val, row, node = heapq.heappop(listNodesHeap)

            if node.next:
                heapq.heappush(listNodesHeap, (node.next.val, row, node.next))

            tmp.next = node
            tmp = tmp.next

        return dummy.next

lists = [ListNode(1,ListNode(4, ListNode(5))),ListNode(1,ListNode(3,ListNode(4))),ListNode(2,ListNode(6))]

sol = Solution()
res = sol.mergeKLists(lists)
while res:
    print(res.val)
    res = res.next
