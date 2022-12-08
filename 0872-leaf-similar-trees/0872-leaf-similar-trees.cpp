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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        find(root1, leaf1);
        find(root2, leaf2);
        return leaf1 == leaf2;
    }
    
    void find(TreeNode* root, vector<int> &leaf) {
        if(root->left || root->right) {
            if(root->left) find(root->left, leaf);
            if(root->right) find(root->right, leaf);
        }
        else {
            leaf.push_back(root->val);
        }
    }
};