class Solution {
public:
    bool winnerSquareGame(int n) {
        return check(n) == 1;
    }
    
    short check(int n) {
        if(n == 0) return -1;
        else if(dp[n]) return dp[n];
        
        for(int i = sqrt(n); i > 0; i--)
            if((dp[n - i * i] = check(n - i * i)) == -1) return 1;

        return -1;
    }
    
    static vector<short> dp;
};

vector<short> Solution::dp = vector<short>(100001);
