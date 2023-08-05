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
                    
                    if(left == 0) {
                        for(auto &&rnode : dp[right]) {
                            TreeNode *root = new TreeNode(r);
                            root->right = helper(rnode, r, i);
                            temp.push_back(root);
                        }
                    }
                    else if(right == 0) {
                        for(auto &&lnode : dp[left]) {
                            TreeNode *root = new TreeNode(r);
                            root->left = lnode;
                            temp.push_back(root);
                        }
                    }
                    else {
                        for(auto &&lnode : dp[left]) {
                            for(auto &&rnode : dp[right]) {
                                TreeNode *root = new TreeNode(r);
                                root->left = lnode;
                                root->right = helper(rnode, r, i);
                                temp.push_back(root);
                            }
                        }
                    }
                }
                
                dp.push_back(temp);
            }
        }
    }
    
    TreeNode *helper(TreeNode *model, int cur, int all) {
        TreeNode *temp = new TreeNode(model->val + cur);
        
        if(model->left) temp->left = helper(model->left, cur, all);
        if(model->right) temp->right = helper(model->right, cur, all);
        
        return temp;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return dp[n];
    }
};

vector<vector<TreeNode*>> Solution::dp;