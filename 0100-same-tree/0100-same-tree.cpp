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
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> a, b;
        DFS(p, a);
        DFS(q, b);
        return a == b;
    }

    void DFS(TreeNode *root, vector<int> &v)
    {
        if (root)
        {
            v.push_back(root->val);
            DFS(root->left, v);
            DFS(root->right, v);
        }
        else
            v.push_back(-1);
    }
};