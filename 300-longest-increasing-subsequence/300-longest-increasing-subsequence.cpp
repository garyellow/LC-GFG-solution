class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> dp;
        
        for(auto &&i : nums)
        {
            for(auto &&cur :dp)
            {
                if(cur.first >= i) break;
                else dp[i] = max(dp[i], cur.second + 1);
            }
            
            dp[i] = max(dp[i], 1);
        }
        
        return max_element(dp.begin(), dp.end(), [](auto &x, auto &y){ return x.second < y.second; })->second;
    }
};