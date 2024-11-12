class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        items.push_back(vector<int>({0, 0}));
        sort(items.begin(), items.end());

        int last = 0;
        for(auto &item : items) {
            last = item.back() = max(last, item.back());
        }

        vector<int> ans;
        for (auto& query : queries) {
            auto target = upper_bound(items.begin(), items.end(), vector<int>({query, INT_MAX})) - 1;
            ans.emplace_back(target->back());
        }

        return ans;
    }
};