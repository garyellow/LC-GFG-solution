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
    vector<double> ans;
    vector<int> cnt;
    int max_depth = -1;
    
    vector<double> averageOfLevels(TreeNode* root) {
        if(root) 
            next(root, 0);
        
        for(int i = 0; i < ans.size(); i++)
            ans[i] /= cnt[i];
        
        return ans;
    }
    
    void next(TreeNode* now, int depth) {
        if(depth > max_depth)
        {
            ans.push_back(0);
            cnt.push_back(0);
            max_depth = depth;
        }
        
        ans[depth] += now->val;
        cnt[depth]++;
        if(now->left) next(now->left, depth + 1);
        if(now->right) next(now->right, depth + 1);
    }
};