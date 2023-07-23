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
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp({{}, {new TreeNode()}});
        
        while(dp.size() <= n) {
            vector<TreeNode*> cur;
            
            for(int i = 1; i < dp.size() - 1; i++) {
                for(auto &&left: dp[i]) {
                    for(auto &&right : dp[dp.size() - i - 1]) {
                        cur.push_back(new TreeNode(0, left, right));
                    }
                }
            }
            
            dp.push_back(cur);
        }
        
        return dp.back();
    }
};