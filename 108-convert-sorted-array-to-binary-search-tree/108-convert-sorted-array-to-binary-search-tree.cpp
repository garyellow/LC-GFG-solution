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
    TreeNode* sortedArrayToBST(vector<int>& nums, int start = -1, int end = -1) {
        if(start >= 0 && start == end) return nullptr;
        else if(start < 0) start = 0, end = nums.size();
        
        int half = (start + end) / 2;
        
        return new TreeNode(nums[half], sortedArrayToBST(nums, start, half), sortedArrayToBST(nums, half + 1, end));
    }
};