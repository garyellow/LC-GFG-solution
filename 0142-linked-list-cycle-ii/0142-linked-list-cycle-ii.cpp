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
    ListNode *detectCycle(ListNode *head) {
        for(unordered_set<ListNode *> hash; head; head = head->next)
            if(hash.count(head) > 0) return head;
            else hash.insert(head);
        
        return NULL;
    }
};