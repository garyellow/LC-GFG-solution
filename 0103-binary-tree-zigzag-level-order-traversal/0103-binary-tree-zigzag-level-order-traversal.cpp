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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> bfs({root});
        
        for(int level = 1; bfs.size(); level++) {
            vector<int> cur;
            
            for(int n = bfs.size(); n--;) {
                auto temp = bfs.front();
                bfs.pop();
                
                cur.push_back(temp->val);
                if(temp->left) bfs.push(temp->left);
                if(temp->right) bfs.push(temp->right);
            }
            
            if(level & 1) ans.push_back(cur);
            else ans.push_back({cur.rbegin(), cur.rend()});
        }
        
        return ans;
    }
};