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
    int pairSum(ListNode* head) {
        vector<int> store;
        
        auto temp = head;
        for(; temp; temp = temp->next) 
            store.push_back(temp->val);
        
        int ans = 0;
        for(int i = 0; i < store.size() / 2; i++) 
            ans = max(ans, store[i] + store[store.size() - i - 1]);
        
        return ans;
    }
};