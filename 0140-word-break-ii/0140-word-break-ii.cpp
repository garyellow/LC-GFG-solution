class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<bool> isGone(s.size());
        vector<vector<string>> dp(s.size());
        
        dfs(0, s, hash, isGone, dp);
        return dp.front(); 
    }
    
    void dfs(int cur, string &s, unordered_set<string> &hash, vector<bool> &isGone, vector<vector<string>> &dp) {
        if(!isGone[cur]) {
            for(int i = 1; cur + i <= s.size(); i++) {
                if(hash.count(s.substr(cur, i))) {
                    if(cur + i == s.size()) {
                        dp[cur].push_back(s.substr(cur, i));
                    }
                    else {
                        dfs(cur + i, s, hash, isGone, dp);
                        for(auto &&str: dp[cur + i]) {
                            dp[cur].push_back(s.substr(cur, i) + ' ' + str);
                        }
                    }
                }
            }
        }
        
        isGone[cur] = true;
    }
};