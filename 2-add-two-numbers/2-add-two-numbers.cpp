/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *save1 = l1, *save2 = l2;
        bool L1 = true;
        
        while(l1 && l2)
        {
            int temp = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1->val = temp;
            l2->val = temp;
            
            if(!l1->next && !l2->next && carry)
                l1->next = new ListNode(0);
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            int temp = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1->val = temp;
            
            if(!l1->next && carry)
                l1->next = new ListNode(0);
            
            l1 = l1->next;
        }
        
        while(l2)
        {
            int temp = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2->val = temp;
            
            if(!l2->next && carry)
                l2->next = new ListNode(0);
            
            l2 = l2->next;
            
            L1 = false;
        }
        
        return L1 ? save1 : save2;
    }
};