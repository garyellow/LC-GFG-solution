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
    unordered_map<int, TreeNode*> record;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(auto &&i : preorder)
            record[i] = new TreeNode(i);
        
        return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre1, int pre2, int in1, int in2) {
        if(in1 >= in2) return nullptr;
        
        int n = find(inorder.begin() + in1, inorder.begin() + in2, preorder[pre1]) - (inorder.begin() + in1);
        record[preorder[pre1]]->left = buildTree(preorder, inorder, pre1 + 1, pre1 + n + 1, in1, in1 + n);
        record[preorder[pre1]]->right = buildTree(preorder, inorder, pre1 + n + 1, pre2, in1 + n + 1, in2);
        
        return record[preorder[pre1]];
    }
};