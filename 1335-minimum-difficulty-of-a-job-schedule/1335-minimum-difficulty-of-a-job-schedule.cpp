class Solution {
public:
    vector<vector<int>> dp;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        dp = vector<vector<int>>(jobDifficulty.size(), vector<int>(d + 1, -1));
        
        return dfs(0, d, jobDifficulty);
    }
    
    int dfs(int last_cut, int remain, vector<int>& jobDifficulty) {
        if(dp[last_cut][remain] >= 0) return dp[last_cut][remain];
        else if(remain == 1) {
            return dp[last_cut][remain] = *max_element(jobDifficulty.begin() + last_cut, jobDifficulty.end());
        }
        else {
            int max_num = 0;
            int cnt = INT_MAX;
            for(int i = last_cut; i <= jobDifficulty.size() - remain; i++) {
                max_num = max(max_num, jobDifficulty[i]);
                cnt = min(cnt, max_num + dfs(i + 1, remain - 1, jobDifficulty));
            }
            
            return dp[last_cut][remain] = cnt;
        }
    }
};