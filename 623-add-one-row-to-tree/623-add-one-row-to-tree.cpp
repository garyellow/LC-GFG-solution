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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return new TreeNode(val, root, nullptr);
        
        queue<TreeNode*> bfs({root});
        
        for(int level = 1; bfs.size() && level < depth; level++)
        {
            for(int n = bfs.size(); n--;) {
                auto temp = bfs.front();
                bfs.pop();
                if(level == depth - 1)
                {
                    temp->left = new TreeNode(val, temp->left, nullptr);
                    temp->right = new TreeNode(val, nullptr, temp->right);
                }
                else
                {
                    if(temp->left) bfs.push(temp->left);
                    if(temp->right) bfs.push(temp->right);
                }
            }
        }
        
        return root;
    }
};