class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> pre(2 * nums.size() + 1, 0);

        pre[nums.size()] = 1;

        int cnt = nums.size();
        long long presum = 0;
        long long ans = 0;

        for (auto x : nums) {
            if (x == target) {
                presum += pre[cnt];

                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;

                presum -= pre[cnt];
                ++pre[cnt];
            }

            ans += presum;
        }

        return ans;
    }
};