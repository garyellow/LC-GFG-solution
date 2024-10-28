class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<long, int> streak_table;

        for (auto&& num : nums) {
            int root = sqrt(num);
            if (root * root == num && streak_table.count(root)) {
                streak_table[num] = streak_table[root] + 1;
            } else {
                streak_table[num] = 1;
            }
        }

        auto ans = max_element(streak_table.begin(), streak_table.end(), [](auto& x, auto& y) {
            return x.second < y.second; 
        })->second;

        return ans > 1 ? ans : -1;
    }
};