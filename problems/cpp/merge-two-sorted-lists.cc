/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // This function takes one list node pointer and
    // returns a copy of the list starting at that
    // pointer till the end
    // If the list node pointer is null, it returns
    // null
    inline ListNode* copyList (ListNode* l) {
        if (!l) return l;
        
        ListNode* head = new ListNode(l->val), *newl = head;
        
        while (l->next) {
            newl->next = new ListNode(l->next->val);
            l = l->next;
            newl = newl->next;
        }
        
        return head;
    }

    // This function takes two non-null list node pointers
    // and returns a new node with the value of
    // min(l1->val, l2->val). It also advances the pointer
    // of the list whose value is smaller
    // In case of a tie, l1 is advanced
    inline ListNode* newMinNode (ListNode*& l1, ListNode*& l2) {    
        ListNode* newNode;
        if (l1->val <= l2->val) {
            //cout << "l1 node: " << l1->val << "\n";
            newNode = new ListNode(l1->val);
            l1 = l1->next;
        } else {
            //cout << "l2 node: " << l2->val << "\n";
            newNode = new ListNode(l2->val);
            l2 = l2->next;
        }
        return newNode;
    }
        
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // If either (or both) of lists is empty, return
        // a copy of the other list
        if (!l1) {
            return copyList(l2);
        }
        if (!l2) {
            return copyList(l1);
        }
        
        // If there is at least one node in each list, merge
        // the two lists
        ListNode* head = newMinNode(l1, l2), *l3 = head;
        
        while (l1 && l2) {
            l3->next = newMinNode(l1, l2);
            l3 = l3->next;
        }
        
        // NOTE: The while loops below will execute at most
        // exclusively

        // If l1 still has nodes, copy all the nodes and
        // append to l3
        if (l1) {
            l3->next = copyList(l1);
        }
        
        // If l2 still has nodes, copy all the nodes and
        // append to l3
        if (l2) {
            l3->next = copyList(l2);
        }
        
        return head;
    }
};
