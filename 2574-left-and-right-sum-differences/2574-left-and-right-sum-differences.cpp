class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);

        vector<int> result;

        for (auto num : nums) {
            r -= num;
            result.emplace_back(abs(r - l));
            l += num;
        }

        return result;
    }
};