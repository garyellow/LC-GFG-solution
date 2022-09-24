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
    vector<vector<int>> ans;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root) find(root, targetSum, vector<int>(), 0);
        
        return ans;
    }
    
    void find(TreeNode* root, const int &targetSum, vector<int> temp, int cur)
    {
        temp.push_back(root->val);
        cur += root->val;
        
        if(root->left)
            find(root->left, targetSum, temp, cur);
        
        if(root->right)
            find(root->right, targetSum, temp, cur);
        
        if(!root->left && !root->right)
            if(cur == targetSum) ans.push_back(temp);
    }
};