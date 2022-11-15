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
    int countNodes(TreeNode* root) {
        int l, r;
        
        auto cur = root;
        for(l = 0; cur; cur = cur->left) 
            l++;
        
        cur = root;
        for(r = 0; cur; cur = cur->right) 
            r++;
        
        if(l == r) return pow(2, l) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};