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
    deque<vector<int>> ans = deque<vector<int>>(1,vector<int>());
    int min = 0, max = 0, index = 0;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root, 0, 0);
        
        for(auto &&i : ans)
        {
            sort(i.begin(), i.end(), [](auto &x, auto &y){ return (x % 10000 < y % 10000); });
            stable_sort(i.begin(), i.end(), [](auto &x, auto &y){ return (x / 10000 < y / 10000); });
            
            for(auto &&j : i)
                j %= 10000;
        }
            
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void DFS(TreeNode* now, int x, int y)
    {
        if(y < min)
        {
            ans.push_front(vector<int>());
            index++;
            min = y;
        }
        
        if(y > max)
        {
            ans.push_back(vector<int>());
            max = y;
        }
        
        ans[index + y].push_back(now->val + 10000 * x);
        if(now->left) DFS(now->left, x + 1, y - 1);
        if(now->right) DFS(now->right, x + 1, y + 1);
    }
};