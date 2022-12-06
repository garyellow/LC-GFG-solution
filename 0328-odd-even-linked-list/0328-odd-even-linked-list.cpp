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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *temp = head, *temp_next = head->next, *even = head->next;
        
        int cnt;
        for(cnt = 0; temp_next->next != nullptr; cnt++)
        {
            temp->next = temp_next->next;
            temp = temp_next;
            temp_next = temp_next->next;
        }
        
        if(cnt & 1) {
            temp_next->next = even;
            temp->next = nullptr;
        }
        else {
            temp->next = even;
            temp_next->next = nullptr;
        }
        
        return head;
    }
};