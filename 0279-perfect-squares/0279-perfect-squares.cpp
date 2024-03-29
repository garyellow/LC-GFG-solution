class Solution {
public:
    vector<int> dp = vector<int>(1e5 + 1);
    int numSquares(int n) {
        if(dp[n] || n == 0) return dp[n];
            
        int temp = INT_MAX;
        for(int i = 1; n - i * i >= 0; i++)
            temp = min(temp, 1 + numSquares(n - i * i));
        
        return dp[n] = temp;
    }
};