class Solution {
public:
    unordered_map<int, int> dp;
    int ways(vector<string>& pizza, int k, int r = 0, int c = 0) {
        int cnt = 0;
        
        for(int cr = r; cr < pizza.size(); cr++) {
            for(int cc = c; cc < pizza.front().size(); cc++) {
                if(pizza[cr][cc] == 'A') {
                    cnt++;
                }
            }
        }
        
        if(k == 1) return dp[encode(r, c, k)] = bool(cnt);
        if(k > cnt) return dp[encode(r, c, k)] = false;
        
        if(!dp.count(encode(r, c, k))) {
            for(int nr = r + 1; nr < pizza.size(); nr++) {
                bool apple = false;
                
                for(int cr = r; cr < nr; cr++) {
                    for(int cc = c; cc < pizza.front().size(); cc++) {
                        if(pizza[cr][cc] == 'A') {
                            apple = true;
                            cr = nr;
                            break;
                        }
                    }
                }
                
                if(apple) {
                    dp[encode(r, c, k)] = (0L + dp[encode(r, c, k)] + ways(pizza, k - 1, nr, c)) % int(1e9 + 7);
                }
            }
            
            for(int nc = c + 1; nc < pizza.front().size(); nc++) {
                bool apple = false;
                
                for(int cr = r; cr < pizza.size(); cr++) {
                    for(int cc = c; cc < nc; cc++) {
                        if(pizza[cr][cc] == 'A') {
                            apple = true;
                            cr = pizza.size();
                            break;
                        }
                    }
                }
                
                if(apple) {
                    dp[encode(r, c, k)] = (0L + dp[encode(r, c, k)] + ways(pizza, k - 1, r, nc)) % int(1e9 + 7);
                }
            }
        }
        
        return dp[encode(r, c, k)];
    }
    
    inline int encode(int &r, int &c, int &k) {
        return r * 50 * 50 + c * 50 + k;
    }
};