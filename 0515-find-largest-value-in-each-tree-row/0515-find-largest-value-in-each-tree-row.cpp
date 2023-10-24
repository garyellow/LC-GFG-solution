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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> bfs({root});

        vector<int> ans;
        while(bfs.size()) {
            auto m = INT_MIN;
            for(auto n = bfs.size(); n--;) {
                auto temp = bfs.front();
                bfs.pop();
                m = max(m, temp->val);
                if(temp->left) bfs.push(temp->left);
                if(temp->right) bfs.push(temp->right);
            }
            ans.push_back(m);
        }

        return ans;
    }
};