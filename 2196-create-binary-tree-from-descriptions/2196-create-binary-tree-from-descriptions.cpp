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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<pair<int, bool>, int> dict;
        unordered_set<int> gone;

        for (const auto& description : descriptions) {
            dict[{description[0], description[2]}] = description[1];

            gone.insert(description[1]);
        }

        for (const auto& description : descriptions) {
            if (!gone.count(description[0])) {
                return generate(description[0], dict);
            }
        }

        return nullptr;
    }

    TreeNode* generate(int cur, map<pair<int, bool>, int>& dict) {
        auto left = dict.count({cur, true}) ? generate(dict[{cur, true}], dict)
                                            : nullptr;
        auto right = dict.count({cur, false})
                         ? generate(dict[{cur, false}], dict)
                         : nullptr;

        return new TreeNode(cur, left, right);
    }
};