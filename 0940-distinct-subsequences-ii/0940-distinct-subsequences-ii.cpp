class Solution {
public:
    int distinctSubseqII(string s) {
        int tot = 0;
        vector<int> dp(26);

        for (auto c : s) {
            c -= 'a';
            int add = (tot - dp[c] + int(1e9 + 7)) % int(1e9 + 7);
            dp[c] = 1 + tot;
            tot = (dp[c] + add) % int(1e9 + 7);
        }

        return tot;
    }
};