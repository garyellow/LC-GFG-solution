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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *check = head;
        int len;
        for(len = 0; check != nullptr; len++, check = check->next);
    
        ListNode *a, *b;
        check = head;
        for(int i = 0; check != nullptr; i++)
        {
            if(i == k - 1)
                a = check;
            if(i == len - k)
                b = check;
            
            check = check->next;
        }
        
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
        
        return head;
    }
};