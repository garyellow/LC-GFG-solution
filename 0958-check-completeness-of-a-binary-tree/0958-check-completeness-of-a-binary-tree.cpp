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
    bool isCompleteTree(TreeNode* root) {
        bool end = false;
        
        queue<TreeNode*> bfs({root});
        
        while(bfs.size()) {
            for(int n = bfs.size(); n--;) {
                auto temp = bfs.front();
                bfs.pop();
                
                if(!end && temp->left) bfs.push(temp->left);
                else if(!end && !temp->left) end = true;
                else if(end && temp->left) return false;
                
                if(!end && temp->right) bfs.push(temp->right);
                else if(!end && !temp->right) end = true;
                else if(end && temp->right) return false;
            }
        }
        
        return true;
    }
};