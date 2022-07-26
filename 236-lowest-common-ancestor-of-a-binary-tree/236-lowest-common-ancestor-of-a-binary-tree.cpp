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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> first, second; 
        find(root, p, first);
        find(root, q, second);
        
        int i;
        for(i = 0; i < min(first.size(), second.size()) && first[i] == second[i]; i++);
        
        return first[i - 1];
    }
    
    bool find(TreeNode* root, TreeNode* &target, vector<TreeNode*> &before)
    {
        if(root)
        {
            before.push_back(root);
            if(root == target)
                return true;
            else
            {
                if(find(root->left, target, before))
                    return true;
                if(find(root->right, target, before))
                    return true;
            }
            before.pop_back();
        }
        
        return false;
    }
};