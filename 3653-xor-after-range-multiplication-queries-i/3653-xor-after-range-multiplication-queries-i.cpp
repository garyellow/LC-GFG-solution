class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& t : queries) {
            int l = t[0];
            int r = t[1];
            int k = t[2];
            int v = t[3];
            int idx = l;
            while (idx <= r) {
                long long temp = nums[idx];
                nums[idx] = (temp * v) % int(1e9 + 7);
                idx += k;
            }
        }
        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};