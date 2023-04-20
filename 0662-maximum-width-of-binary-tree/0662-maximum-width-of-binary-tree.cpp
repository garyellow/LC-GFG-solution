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
    vector<size_t> record = vector<size_t>(3001);
    size_t ans = 0;
    
    int widthOfBinaryTree(TreeNode *root)
    {
        find(root, 1, 1);
        return ans;
    }

    void find(TreeNode *root, int depth, size_t address)
    {
        if (record[depth] == 0) record[depth] = address;
        ans = max(ans, address - record[depth] + 1);

        if (root->left) find(root->left, depth + 1, address * 2);
        if (root->right) find(root->right, depth + 1, address * 2 + 1);
    }
};