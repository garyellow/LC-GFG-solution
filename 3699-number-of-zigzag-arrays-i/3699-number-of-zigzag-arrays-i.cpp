class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {
            ranges::reverse(dp);
            int sum = 0;
            for (auto& d : dp)
                sum = (sum + exchange(d, sum)) % int(1e9 + 7);
        }

        return ((accumulate(dp.begin(), dp.end(), 0LL) % int(1e9 + 7)) << 1) %
               int(1e9 + 7);
    }
};