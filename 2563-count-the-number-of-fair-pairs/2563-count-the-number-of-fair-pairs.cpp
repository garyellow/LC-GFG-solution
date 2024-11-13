class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt += upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
        }

        return cnt;
    }
};