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
    int maxLevelSum(TreeNode* root) {
        int ans = 1, m = root->val;
        
        queue<TreeNode*> bfs({root});
        
        for(int level = 1; bfs.size(); level++) {
            int sum = 0;
            
            for(int n = bfs.size(); n--;) {
                auto temp = bfs.front();
                sum += temp->val;
                
                if(temp->left) bfs.push(temp->left);
                if(temp->right) bfs.push(temp->right);
                
                bfs.pop();
            }
            
            if(sum > m) {
                m = sum;
                ans = level;
            }
        }
        
        return ans;
    }
};