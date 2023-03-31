class Solution {
public:
    unordered_map<int, int> dp;
    vector<vector<int>> prefix;
    int ways(vector<string>& pizza, int k, int r = 0, int c = 0) {
        if(prefix.empty()) {
            prefix = vector<vector<int>>(pizza.size(), vector<int>(pizza.front().size()));
            
            for(int cr = pizza.size() - 1; cr >= 0; cr--)
                for(int cc = pizza.front().size() - 1; cc >= 0; cc--) {
                    if(pizza[cr][cc] == 'A') prefix[cr][cc]++;
                    
                    if(cr == pizza.size() - 1 && cc == pizza.front().size() - 1) continue;
                    else if(cr == pizza.size() - 1) prefix[cr][cc] += prefix[cr][cc + 1];
                    else if(cc == pizza.front().size() - 1) prefix[cr][cc] += prefix[cr + 1][cc];
                    else prefix[cr][cc] += prefix[cr + 1][cc] + prefix[cr][cc + 1] - prefix[cr + 1][cc + 1];
                }
        }
        
        if(k == 1) return dp[encode(r, c, k)] = bool(prefix[r][c]);
        if(k > prefix[r][c]) return dp[encode(r, c, k)] = false;
        
        if(!dp.count(encode(r, c, k))) {
            for(int nr = r + 1; nr < pizza.size(); nr++) 
                if(prefix[r][c] - prefix[nr][c]) 
                    dp[encode(r, c, k)] = (0L + dp[encode(r, c, k)] + ways(pizza, k - 1, nr, c)) % int(1e9 + 7);
            
            for(int nc = c + 1; nc < pizza.front().size(); nc++) 
                if(prefix[r][c] - prefix[r][nc]) 
                    dp[encode(r, c, k)] = (0L + dp[encode(r, c, k)] + ways(pizza, k - 1, r, nc)) % int(1e9 + 7);
        }
        
        return dp[encode(r, c, k)];
    }
    
    inline int encode(int &r, int &c, int &k) {
        return r * 50 * 50 + c * 50 + k;
    }
};