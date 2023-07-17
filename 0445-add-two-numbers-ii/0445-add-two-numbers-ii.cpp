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
        vector<short> num1, num2;
        
        for(; l1; l1 = l1->next) num1.push_back(l1->val);
        for(; l2; l2 = l2->next) num2.push_back(l2->val);
        
        bool carry = false;
        
        ListNode* cur = nullptr;
        while(num1.size() || num2.size()) {
            int temp = carry;
            if(num1.size()) temp += num1.back(), num1.pop_back();
            if(num2.size()) temp += num2.back(), num2.pop_back();
            
            carry = temp > 9;
            cur = new ListNode(temp % 10, cur);
        }
        
        if(carry) cur = new ListNode(1, cur);
        
        return cur;
    }
};