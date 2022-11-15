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
    int countNodes(TreeNode* root, int l = 0, int r = 0) {
        if(l == 0) for(auto cur = root; cur; cur = cur->left, l++);
        if(r == 0) for(auto cur = root; cur; cur = cur->right, r++); 
        
        if(l == r) return pow(2, l) - 1;
        else return 1 + countNodes(root->left, l - 1, 0) + countNodes(root->right, 0, r - 1);
    }
};