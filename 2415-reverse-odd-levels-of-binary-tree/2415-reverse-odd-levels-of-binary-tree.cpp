/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> odd({root}), even;

        while (odd.size() || even.size()) {
            vector<TreeNode*> children;
            if (odd.size()) {
                bfs(odd, even, children);

                for (int i = 0; i < children.size() / 2; i++) {
                    swap(children[i]->val,
                         children[children.size() - i - 1]->val);
                }
            } else {
                bfs(even, odd, children);
            }
        }

        return root;
    }

    void bfs(queue<TreeNode*>& from, queue<TreeNode*>& to,
             vector<TreeNode*>& children) {
        if (from.front() == nullptr)
            return;

        while (from.size()) {
            auto cur = from.front();
            from.pop();

            if (cur->left != nullptr) {
                to.push(cur->left);
                children.push_back(cur->left);
                to.push(cur->right);
                children.push_back(cur->right);
            }
        }
    }
};