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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> bfs;
        if(root) bfs.push(root);
        
        while(bfs.size())
        {
            vector<int> temp;
            temp.reserve(bfs.size());
            
            for(int n = bfs.size(); n--;)
            {
                temp.push_back(bfs.front()->val);
                if(bfs.front()->left) bfs.push(bfs.front()->left);
                if(bfs.front()->right) bfs.push(bfs.front()->right);
                bfs.pop();
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};