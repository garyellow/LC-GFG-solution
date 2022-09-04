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
    map<int, vector<int>> record =  map<int, vector<int>>({{0, vector<int>()}});
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root, 0, 0);
        
        for(auto &&[cnt, arr] : record)
        {
            sort(arr.begin(), arr.end(), [](auto &x, auto &y){ return (x % 10000 < y % 10000); });
            stable_sort(arr.begin(), arr.end(), [](auto &x, auto &y){ return (x / 10000 < y / 10000); });
            
            for(auto &&num : arr)
                num %= 10000;
        }
            
        vector<vector<int>> ans;
        for(auto &&[cnt, arr] : record)
            ans.push_back(arr);
        
        return ans;
    }
    
    void DFS(TreeNode* now, int x, int y)
    {
        record[y].push_back(now->val + 10000 * x);
        if(now->left) DFS(now->left, x + 1, y - 1);
        if(now->right) DFS(now->right, x + 1, y + 1);
    }
};