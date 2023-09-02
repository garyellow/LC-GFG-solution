class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<char, vector<string>> dic;
        vector<int> dp(s.size(), 100);

        for(auto &&item : dictionary) {
            dic[item.front()].push_back(item);
        }

        return helper(0, s, dic, dp);
    }

    int helper(int cur, string &s, unordered_map<char, vector<string>> &dic, vector<int> &dp) {
        if(cur == s.size()) return 0;

        if(dp[cur] == 100) {
            for(int skip = 0; cur + skip < s.size(); skip++) {
                for(auto &&item : dic[s[cur + skip]]) {
                    if(cur + skip + item.size() <= s.size() && item == s.substr(cur + skip, item.size())) {
                        dp[cur] = min(dp[cur], skip + helper(cur + skip + item.size(), s, dic, dp));
                    }
                }

                dp[cur] = min(dp[cur], (int)s.size() - cur);
            }
        }

        return dp[cur];
    }
};