class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int ans = 1;
        sort(words.begin(), words.end(), [](auto &l, auto &r) { return l.size() < r.size(); });
        for (auto &&word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(prev)) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                    ans = max(ans, dp[word]);
                }
            }
        }

        for(auto [a,b]:dp){
            cout << a << ' ' << b << endl;
        }
        return ans;
    }
};