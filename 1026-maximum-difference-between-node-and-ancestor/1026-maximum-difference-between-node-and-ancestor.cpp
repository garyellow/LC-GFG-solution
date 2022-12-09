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
    int max_dif = 0;
    vector<int> record;

    int maxAncestorDiff(TreeNode *root)
    {
        record.push_back(root->val);

        if(root->left) maxAncestorDiff(root->left);
        if(root->right) maxAncestorDiff(root->right);

        if (!root->left && !root->right)
        {
            auto [x, y] = minmax_element(record.begin(), record.end());
            max_dif = max(max_dif, (int)abs(*x - *y));
        }

        record.pop_back();

        return max_dif;
    }
};