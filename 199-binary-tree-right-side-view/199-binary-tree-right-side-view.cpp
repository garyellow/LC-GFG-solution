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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> record;
        queue<TreeNode*> bfs;
        
        if(root) bfs.push(root);
        
        while(bfs.size())
        {
            record.push_back(bfs.back()->val);
            
            for(int n = bfs.size(); n--;)
            {
                if(bfs.front()->left) bfs.push(bfs.front()->left);
                if(bfs.front()->right) bfs.push(bfs.front()->right);
                bfs.pop();
            }
        }
        
        return record;
    }
};