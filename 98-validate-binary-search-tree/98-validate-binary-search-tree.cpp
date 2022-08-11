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
    bool isValidBST(TreeNode* root, long small = INT64_MIN, long big = INT64_MAX) {
        if(root == nullptr) return true;
        else if(root->val <= small || root->val >= big) return false;
        else return isValidBST(root->left, small, root->val) && isValidBST(root->right, root->val, big);
    }
};