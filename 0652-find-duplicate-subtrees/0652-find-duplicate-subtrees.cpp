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
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        dfs(root, hash);
        return ans;
    }
    
    string dfs(TreeNode* root, unordered_map<string, int>& hash) {
        if(!root) return "";
        
        string cur = to_string(root->val) + ',' + dfs(root->left, hash) + "," + dfs(root->right, hash);
        
        if(hash[cur]++ == 1)
            ans.push_back(root);

        return cur;
    }
};