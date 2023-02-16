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
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr) return 0;

        queue<TreeNode *> bfs({root});

        int depth;
        for (depth = 0; !bfs.empty(); depth++)
        {
            for (int n = bfs.size(); n--;)
            {
                TreeNode *temp = bfs.front();
                bfs.pop();

                if (temp->left)
                    bfs.push(temp->left);
                if (temp->right)
                    bfs.push(temp->right);
            }
        }

        return depth;
    }
};