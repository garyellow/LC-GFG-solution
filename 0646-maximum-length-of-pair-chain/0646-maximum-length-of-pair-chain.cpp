class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &x, auto &y){
            return x.back() < y.back();
        });

        vector<int> dp(2002);
        for(int i = 1, index = 0; i <= 2001; i++) {
            dp[i] = dp[i - 1];

            for(; index < pairs.size() && pairs[index].back() + 1 == i - 1000; index++) {
                dp[i] = max(dp[i], dp[pairs[index].front() + 1000] + 1);
            }
        }

        return dp.back();
    }
};