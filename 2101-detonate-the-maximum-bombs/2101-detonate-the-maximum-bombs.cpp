class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> g(bombs.size() + 1);
        
        for(int i = 0; i < bombs.size(); i++) {
            for(int j = 0; j < bombs.size(); j++) {
                if(i != j) {
                    long x = pow(bombs[i][0] - bombs[j][0], 2);
                    long y = pow(bombs[i][1] - bombs[j][1], 2);
                    
                    if(x + y <= 1L * bombs[i][2] * bombs[i][2]) {
                        g[i].push_back(j);
                    }
                }
            }
        }
    
        int cnt = 0;
        
        for(int i = 0; i < bombs.size(); i++) {
            vector<bool> isGone(bombs.size());
            isGone[i] = true;
            cnt = max(cnt, detonate(i, isGone, g));
        }
        
        return cnt;
    }
    
    int detonate(int cur, vector<bool> &isGone, vector<vector<int>> &g) {
        int cnt = 1;
        
        for(auto &&next : g[cur]) {
            if(!isGone[next]) {
                isGone[next] = true;
                cnt += detonate(next, isGone, g);
            }
        }
        
        return cnt;
    }
};