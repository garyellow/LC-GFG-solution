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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return head->next;
        int cnt = 0;
        for(auto temp = head; temp; temp = temp->next, cnt++);
        
        auto temp = head;
        for(cnt /= 2, cnt--; cnt; temp = temp->next, cnt--);
        temp->next = temp->next->next;
        
        return head;
    }
};