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
    TreeNode* sortedArrayToBST(vector<int> nums) {
        if(nums.size() == 0) return nullptr;
        int half = nums.size() / 2;
        
        return new TreeNode(nums[half], sortedArrayToBST(vector<int>(nums.begin(), nums.begin() + half)), sortedArrayToBST(vector<int>(nums.begin() + half + 1, nums.end())));
    }
};