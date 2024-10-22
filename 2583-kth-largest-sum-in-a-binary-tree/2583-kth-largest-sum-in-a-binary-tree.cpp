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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levels;
        queue<TreeNode*> bfs({root});

        while(!bfs.empty()) {
            long long temp = 0;
            for(int n = bfs.size(); n--;) {
                auto cur = bfs.front();
                bfs.pop();
                
                temp += cur->val;
                if(cur->left) bfs.push(cur->left);
                if(cur->right) bfs.push(cur->right);
            }

            levels.push_back(temp);
        }

        nth_element(levels.begin(), levels.begin() + k - 1, levels.end(), greater<long long>());
        return k > levels.size() ? -1 : levels[k - 1];
    }
};