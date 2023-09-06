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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        for(int n = k; n--; ans.push_back(new ListNode(-1)));
        vector<ListNode*> cur(ans);
        
        int cnt = 0;
        for(auto temp = head; temp; cnt++, temp = temp->next);
        int r = cnt % k, n = cnt / k;

        for(int i = 0; i < k; i++) {
            for(int x = n + (i < r); x--; head = head->next) {
                cur[i]->next = head;
                cur[i] = cur[i]->next;
            }
            cur[i]->next = nullptr;
        }

        for(int i = 0; i < k; i++) {
            if(ans[i]->val == -1) ans[i] = ans[i]->next;
            else ans[i] = nullptr;
        }

        return ans;
    }
};