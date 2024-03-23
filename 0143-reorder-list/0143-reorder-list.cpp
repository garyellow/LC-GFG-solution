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
    void reorderList(ListNode* head) {
        deque<ListNode*> arr;
        
        for(ListNode* now = head; now; now = now->next)
            arr.push_back(now);
        
        arr.front()->next = NULL;
        ListNode* now = arr.front();
        arr.pop_front();
        for(int cnt = 0; arr.size(); cnt++, now = now->next)
        {
            if(cnt & 1)
            {
                arr.front()->next = NULL;
                now->next = arr.front();
                arr.pop_front();
            }
            else
            {
                arr.front()->next = NULL;
                now->next = arr.back();
                arr.pop_back();
            }
        }
    }
};