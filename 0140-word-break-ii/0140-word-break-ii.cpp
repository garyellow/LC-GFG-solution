class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<bool> isGone(s.size());
        vector<vector<string>> dp(s.size());
        
        return dfs(0, s, hash, isGone, dp); 
    }
    
    vector<string> dfs(int cur, string &s, unordered_set<string> &hash, vector<bool> &isGone, vector<vector<string>> &dp) {
        if(cur == s.size()) {
            return {"find"};
        }
        
        if(!isGone[cur]) {
            for(int i = 1; cur + i <= s.size(); i++) {
                if(hash.count(s.substr(cur, i))) {
                    auto temp = dfs(cur + i, s, hash, isGone, dp);
                    
                    if(temp.size()) {
                        if(temp.front() == "find") {
                            dp[cur].push_back(s.substr(cur, i));
                        }
                        else {
                            for(auto &&str: temp) {
                                dp[cur].push_back(s.substr(cur, i) + ' ' + str);
                            }
                        }
                    }
                }
            }
        }
        
        isGone[cur] = true;
        return dp[cur];
    }
};