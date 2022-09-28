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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        
        auto temp = head;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        
        if(cnt == 1) return nullptr;
        else if(cnt == n) return head->next;
        
        temp = head;
        for(int d = cnt - n - 1; d-- > 0;)
            temp = temp->next;
        
        temp->next = temp->next->next;
        
        return head;
    }
};