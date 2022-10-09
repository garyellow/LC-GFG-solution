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
    bool findTarget(TreeNode *root, const int &k)
    {
        if (hash.count(k - root->val))
            return true;

        hash.insert(root->val);

        if (root->left && findTarget(root->left, k))
            return true;
        if (root->right && findTarget(root->right, k))
            return true;

        return false;
    }

    set<int> hash;
};