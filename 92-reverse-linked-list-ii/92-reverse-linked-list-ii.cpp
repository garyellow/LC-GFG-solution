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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> middle;
        ListNode* front = nullptr, *back = nullptr;
        
        ListNode* cur, *temp;
        cur = temp = new ListNode(0, head);
        
        for(int index = 0; cur; cur = cur->next, index++)
        {
            if(index == left - 1) front = cur;
            if(index == right + 1)
            {
                back = cur;
                break;
            }
            
            if(index >= left && index <= right)
                middle.push(cur);
        }
        
        while(middle.size())
        {
            front->next = middle.top();
            middle.pop();
            front = front->next;
        }
        
        front->next = back;
        
        return temp->next;
    }
};