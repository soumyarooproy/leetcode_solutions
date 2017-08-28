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
    ListNode* duplicateListWithCarry (ListNode* in, int carryin)
    {
        if (in == nullptr) {
            return (carryin? new ListNode(carryin) : nullptr);
        }
        
        int sum = in->val + carryin;
        int carry = sum / 10;
        sum %= 10;
        ListNode* head = new ListNode(sum);
        
        ListNode* out = head;
        in = in->next;
        
        while (in) {
            sum = carry + in->val;
            carry = sum / 10;
            sum %= 10;
            out->next = new ListNode(sum);

            in = in->next;
            out = out->next;
        }
        out->next = carry? new ListNode(carry) : nullptr;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) {
            return duplicateListWithCarry(l2, 0);
        }
        if (l2 == nullptr) {
            return duplicateListWithCarry(l1, 0);
        }
        
        int sum = l1->val + l2->val;
        int carry = sum / 10;
        sum %= 10;
        ListNode* head = new ListNode(sum);
        
        ListNode* l3 = head;
        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 && l2) {
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum %= 10;
            l3->next = new ListNode(sum);

            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
        
        if (l1) {
            l3->next = duplicateListWithCarry(l1, carry);
        } else if (l2) {
            l3->next = duplicateListWithCarry(l2, carry);
        } else {
            l3->next = carry? new ListNode(carry) : nullptr;
        }
        
        return head;
    }
};

/*----------------------------------------------------------------------*/
// Faster and a more compact solution on leetcode
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode result(0),*p=&result;
    bool flag=false;
    while(l1||l2||flag){
        int sum=(l1?l1->val:0)+(l2?l2->val:0)+flag;
        flag=false;
        p->next=new ListNode(sum%10);
        if(sum/10!=0)flag=true;
        p=p->next;
        l1=l1?l1->next:NULL;
        l2=l2?l2->next:NULL;
    }
    return result.next;
}
