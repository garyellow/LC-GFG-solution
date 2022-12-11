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
    double dis = INT_MAX;
    int mid = INT_MAX;
    int maxProduct(TreeNode* root) {
        int sum = add(root);
        find(root, sum / 2.0);
        
        return (1L * mid * (sum - mid)) % int(1e9 + 7);
    }
    
    int add(TreeNode* &root) {
        if(!root) return 0;
        else return root->val + add(root->left) + add(root->right);
    }
    
    int find(TreeNode* &root, const double &sum) {
        if(!root) return 0;
        
        int cnt = root->val + find(root->left, sum) + find(root->right, sum);
        if(fabs(sum - cnt) < dis) {
            dis = fabs(sum - cnt);
            mid = cnt;
        }
        
        return cnt;
    }
};