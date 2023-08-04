class Solution {
public:
    unordered_set<string> hash;
    unordered_set<int> isGone;
    bool wordBreak(string s, vector<string>& wordDict) {
        hash = unordered_set<string>(wordDict.begin(), wordDict.end());
        
        return dfs(0, s); 
    }
    
    bool dfs(int cur, string &s) {
        if(cur == s.size()) {
            return true;
        }
        
        if(!isGone.count(cur)) {
            for(int i = 1; cur + i <= s.size(); i++) {
                if(hash.count(s.substr(cur, i))) {
                    if(dfs(cur + i, s)) {
                        return true;
                    }
                }
            }
        }
        
        isGone.insert(cur);
        return false;
    }
};