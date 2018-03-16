# 03/16/2018
# Time  : O(n), n = total number of nodes across the k lists
# Space : O(k)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        
        # Use a min heap to keep track of the mininum value across all the lists; also
        # track the list index along with the value
        min_heap = []
        for i, head in enumerate(lists):
            if head:
                heapq.heappush(min_heap, (head.val, i))

        # Create a new dummy node to indiciate the (dummy) pre-head of the result list
        result_list_pre_head = ListNode(0)
        node = result_list_pre_head
        while min_heap:
            # Pop the next smallest value from the heap and the index of the list
            # where it belongs
            next_node_list_index = heapq.heappop(min_heap)[1]
            next_node = lists[next_node_list_index]
            
            # Attach the next node to the end of the result list
            node.next = next_node
            
            # If the list has more nodes, push the next largest item into the heap
            if next_node.next:
                heapq.heappush(min_heap, (next_node.next.val, next_node_list_index))
            
            # Advance the list pointer for the list
            lists[next_node_list_index] = next_node.next
            
            # Advance the end of the result list
            node = node.next
            node.next = None
        
        return result_list_pre_head.next
