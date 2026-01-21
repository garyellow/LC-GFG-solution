class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            unsigned p = nums[i];
            if (p == 2)
                continue;
            unsigned lastB = countr_one(p) - 1;
            ans[i] = p & ~(1u << (lastB));
        }
        return ans;
    }
};