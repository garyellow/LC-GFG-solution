class Solution {
public:
    vector<vector<int>> dp;
    int getLengthOfOptimalCompression(string s, int k) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return find(s, 0, k);
    }
    
    int find(string &s, int left, int k) {
        int temp = k;
        if(s.size() - left <= temp) return 0;
        if(dp[left][temp] >= 0) return dp[left][temp];
        
        int res = temp ? find(s, left + 1, temp - 1) : 10000, c = 1;
        for(int i = left + 1; i <= s.size(); ++i) {
            res = min(res, find(s, i, temp) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 :0))));
            if(i == s.size()) break;
            if(s[i] == s[left]) ++c;
            else if(--temp < 0) break;
        }
        
        return dp[left][k] = res;
    }
};