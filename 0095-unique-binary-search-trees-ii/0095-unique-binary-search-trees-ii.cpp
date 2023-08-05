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
    static vector<vector<TreeNode*>> dp;
    
    Solution() {
        if(dp.empty()) {
            dp.push_back({});
            dp.push_back({{vector<TreeNode*>({new TreeNode(1)})}});
            
            for(int i = 2; i <= 8; i++) {
                vector<TreeNode*> temp;
                
                for(int r = 1; r <= i; r++) {
                    int left = r - 1, right = i - r;
                    
                    for(auto &&lnode : dp[left].size() ? dp[left] : vector<TreeNode*>({nullptr})) {
                        for(auto &&rnode : dp[right].size() ? dp[right] : vector<TreeNode*>({nullptr})) {
                            TreeNode *root = new TreeNode(r);
                            root->left = lnode;
                            root->right = helper(rnode, r);
                            temp.push_back(root);
                        }
                    }
                }
                
                dp.push_back(temp);
            }
        }
    }
    
    TreeNode *helper(TreeNode *model, int cur) {
        if(!model) return nullptr;
        
        TreeNode *temp = new TreeNode(model->val + cur);
        
        if(model->left) temp->left = helper(model->left, cur);
        if(model->right) temp->right = helper(model->right, cur);
        
        return temp;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return dp[n];
    }
};

vector<vector<TreeNode*>> Solution::dp;