class Solution {
public:
    vector<int> dp = vector<int>(1e5 + 1);
    int numSquares(int n) {
        if(n == 0 || dp[n]) return dp[n];
            
        int temp = INT_MAX;
        for(int i = 100; i > 0; i--)
            if(n - i * i >= 0)
                temp = min(temp, 1 + numSquares(n - i * i));
        
        return dp[n] = temp;
    }
};