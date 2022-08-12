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
        if(root->val == p->val || root->val == q->val || (root->val > p->val) == (root->val < q->val))
            return root;
        else
        {
            if(root->val > p->val) return lowestCommonAncestor(root->left, p, q);
            else return lowestCommonAncestor(root->right, p, q);
//             TreeNode* P = root->left ? lowestCommonAncestor(root->left, p, q) : NULL;
//             TreeNode* Q = root->right ? lowestCommonAncestor(root->right, p, q) : NULL;
            
//             if(P && Q) return root;
//             else if(P) return P;
//             else if(Q) return Q;
//             else return NULL;
        }
    }
};