class Solution {
public:
    vector<int> dp;
    int numDecodings(string& s) {
        dp.resize(s.size(), -1);

        return check(s);
    }
    
    int check(string& s, int cur = 0) {
        if(dp[cur] == -1) { 
            if(cur == s.size() - 1) dp[cur] = valid(s.substr(cur));
            else if(cur == s.size() - 2) dp[cur] = valid(s.substr(cur)) + (valid(s.substr(cur, 1)) * check(s, cur + 1));
            else dp[cur] = (valid(s.substr(cur, 1)) * check(s, cur + 1)) + (valid(s.substr(cur, 2)) * check(s, cur + 2));
        }
        
        return dp[cur];
    }
    
    bool valid(string num) {
        return num[0] != '0' && stoi(num) <= 26;
    }
};