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
    bitset<10> sum;
    int pseudoPalindromicPaths(TreeNode* root) {
        sum.flip(root->val);
        
        int temp = 0;
        temp += root->left ? pseudoPalindromicPaths(root->left) : 0;
        temp += root->right ? pseudoPalindromicPaths(root->right) : 0;
        temp += (!root->left & !root->right & sum.count() <= 1) ? 1 : 0;
        
        sum.flip(root->val);
        
        return temp;
    }
};