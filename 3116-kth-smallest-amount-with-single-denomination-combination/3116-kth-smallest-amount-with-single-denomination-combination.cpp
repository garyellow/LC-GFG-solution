class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ranges::sort(coins);
        vector<int> A;

        for (auto coin : coins)
            if (ranges::none_of(A, [&](int x) { return !(coin % x); }))
                A.push_back(coin);

        int n = A.size();
        auto check = [&](long long mid) {
            long long tot = 0;
            for (int i = 1; i <= n; i++) {
                int q = (1 << i) - 1;

                while (q < 1 << n) {
                    long long x = 1;
                    for (int j = 0; j < n; j++)
                        if ((q >> j) & 1)
                            x = lcm(x, A[j]);

                    tot += (mid / x) * (((i & 1) << 1) - 1);

                    int c = q & -q;
                    int r = q + c;
                    q = (((r ^ q) >> 2) / c) | r;
                }
            }
            return tot >= k;
        };

        long long low = k, high = 1ll * A[0] * k;
        return *ranges::lower_bound(views::iota(low, high + 1), true, {},
                                    [&](long long mid) { return check(mid); });
    }
};