// 46 ms, 10/08/2017
// Time  : O(n), 2 passes
// Space : O(n)
// TODO  : Solve it using O(1) space
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        auto pre_new_head = RandomListNode(0);

        // Create the new nodes with the next pointer promtly assigned but the random pointer unassigned;
        // Also note the mapping of an old node to its corresponding new node
        for (auto it = head, it_new = &pre_new_head; it; it = it->next, it_new = it_new->next) {
            RandomListNode* new_node = new RandomListNode(it->label);
            old2new[it] = new_node;
            it_new->next = new_node;
        }
        
        // Now, populate the random pointers
        for (auto it = head; it; it = it->next)
            if (it->random)
                old2new[it]->random = old2new[it->random];

        return pre_new_head.next;
    }
};
