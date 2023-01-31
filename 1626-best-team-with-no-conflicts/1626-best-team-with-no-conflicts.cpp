class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> datas;
        
        for(int i = 0; i < scores.size(); i++)
            datas.push_back({ages[i], scores[i]});
        
        sort(datas.begin(), datas.end());
        
        int ans = 0;
        vector<int> dp(scores.size());
        for(int i = 0; i < scores.size(); i++) {
            dp[i] = datas[i].second;
            for(int j = 0; j < i; j++)
                if(datas[j].second <= datas[i].second)
                    dp[i] = max(dp[i], dp[j] + datas[i].second);
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};