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
    bool hasPathSum(TreeNode* root, int targetSum, int sum = 0) {
        if(!root) return false;
        else if(root->left || root->right) return hasPathSum(root->left, targetSum, sum + root->val) || hasPathSum(root->right, targetSum, sum + root->val);
        else return sum + root->val == targetSum;
    }
};