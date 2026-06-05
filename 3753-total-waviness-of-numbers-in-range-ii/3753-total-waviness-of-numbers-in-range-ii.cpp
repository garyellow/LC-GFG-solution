class Solution {
    string s;
    map<tuple<int, int, int, int, int, int>, pair<long long, long long>> mp;

    pair<long long, long long> dfs(int i, int a, int b, int t, int st,
                                   int len) {
        if (i == s.size())
            return {1, 0};

        auto key = tuple(i, a, b, t, st, len);
        if (mp.count(key))
            return mp[key];

        long long cnt = 0, wav = 0;

        for (int d = 0; d <= (t ? s[i] - '0' : 9); d++) {
            auto [c, w] = dfs(i + 1, b, d, t && d == s[i] - '0', st || d,
                              (st || d) ? len + 1 : 0);

            if (len > 1 && ((a < b && b > d) || (a > b && b < d)))
                w += c;

            cnt += c;
            wav += w;
        }
        return mp[key] = {cnt, wav};
    }

    long long solve(long long n) {
        s = to_string(n);
        mp.clear();
        return dfs(0, 0, 0, 1, 0, 0).second;
    }

public:
    long long totalWaviness(long long l, long long r) {
        return solve(r) - solve(l - 1);
    }
};