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
    int sumNumbers(TreeNode* root, int sum = 0) {
        if(!root) return 0;
        
        sum *= 10;
        sum += root->val;
        
        if(!root->left && !root->right) return sum;
        else return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};