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
    int ans = INT_MAX, temp = -1e5;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root) {
        if(root->left) dfs(root->left);
        
        ans = min(ans, root->val - temp);
        temp = root->val;
        
        if(root->right) dfs(root->right);
    }
};