class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *ranges::max_element(nums);

        vector<long long> freq(maxVal + 1, 0);
        for (auto x : nums)
            freq[x]++;

        vector<long long> divCnt(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            for (int x = g; x <= maxVal; x += g)
                divCnt[g] += freq[x];
        }

        vector<long long> exact(maxVal + 1, 0);

        for (int g = maxVal; g >= 1; g--) {
            exact[g] = divCnt[g] * (divCnt[g] - 1) / 2;
            for (int m = 2 * g; m <= maxVal; m += g)
                exact[g] -= exact[m];
        }

        vector<long long> prefix(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (auto q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) -
                    prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};