class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins, int index = 0) {
        if(dp.capacity() == 0) {
            dp.resize(amount + 1, vector<int>(coins.size(), -1));
        }

        if(amount == 0) return 1;
        if(amount < 0) return 0;

        if(dp[amount][index] == -1) {
            dp[amount][index] = 0;

            for(int i = index; i < coins.size(); i++) {
                dp[amount][index] += change(amount - coins[i], coins, i);
            }
        }
        
        return dp[amount][index];
    }
};