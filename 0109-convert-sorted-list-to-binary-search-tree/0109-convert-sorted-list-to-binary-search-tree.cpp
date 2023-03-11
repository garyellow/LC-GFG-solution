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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        for(;head; head = head->next)
            arr.push_back(head->val);
        
        return arr.size() ? create(0, arr.size() - 1, arr) : nullptr;
    }
    
    TreeNode* create(int l, int r, vector<int>& arr) {
        if(l == r) return new TreeNode(arr[l]);
        else {
            int mid = (l + r) / 2;
            return new TreeNode(arr[mid], l == mid ? nullptr : create(l, mid - 1, arr), create(mid + 1, r, arr));
        }
    }
};