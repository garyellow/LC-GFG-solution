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
    unordered_map<int, TreeNode*> record;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(vector<int>(preorder), vector<int>(inorder));
    }
    
    TreeNode* buildTree(vector<int>&& preorder, vector<int>&& inorder) {
        if(record.empty())
            for(auto &&i : preorder)
                record[i] = new TreeNode(i);
        
        if(inorder.empty()) return nullptr;
        int n = find(inorder.begin(), inorder.end(), preorder.front()) - inorder.begin();
        record[preorder.front()]->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + n + 1), vector<int>(inorder.begin(), inorder.begin() + n));
        record[preorder.front()]->right = buildTree(vector<int>(preorder.begin() + n + 1, preorder.end()), vector<int>(inorder.begin() + n + 1, inorder.end()));
        
        return record[preorder.front()];
    }
};