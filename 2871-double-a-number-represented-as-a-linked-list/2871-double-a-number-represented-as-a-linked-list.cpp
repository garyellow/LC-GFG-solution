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
    ListNode* root = nullptr;
    ListNode* doubleIt(ListNode* head) {
        if(!root) root = head;
        
        int temp = head->val * 2 + (head->next ? doubleIt(head->next)->val : 0);
        head->val = temp % 10;
        return head == root ? (temp / 10 ? new ListNode(temp / 10, head) : head) : new ListNode(temp / 10, head);
    }
};