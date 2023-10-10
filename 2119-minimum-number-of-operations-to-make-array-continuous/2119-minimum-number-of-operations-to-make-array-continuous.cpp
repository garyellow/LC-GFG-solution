class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());

        int cnt = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int e = nums[i] + n - 1;
            auto it = upper_bound(nums.begin(), nums.end(), e);

            cnt = min(cnt, n - int(it - nums.begin()) + i);
        }
        return cnt;
    }
};