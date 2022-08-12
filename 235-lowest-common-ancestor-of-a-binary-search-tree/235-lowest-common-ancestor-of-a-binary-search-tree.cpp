/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> ans;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
        else
        {
            TreeNode* P = root->left ? lowestCommonAncestor(root->left, p, q) : NULL;
            TreeNode* Q = root->right ? lowestCommonAncestor(root->right, p, q) : NULL;
            
            if(P && Q) return root;
            else if(P) return P;
            else if(Q) return Q;
            else return NULL;
        }
    }
};