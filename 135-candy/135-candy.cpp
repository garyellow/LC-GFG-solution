class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() < 2) return ratings.size();
        vector<int> dp(ratings.size());
        
//         dp.front() = ratings.front() < ratings[1];
//         dp.back() = ratings.back() < ratings[ratings.size() - 2];
        
//         for(int i = 1; i <= ratings.size() - 2; i++)
//         {
//             dp[i] = ratings[i] < min(ratings[i - 1], ratings[i + 1]);
//         }
        
        for(int i = 0; i < ratings.size(); i++)
        {
            check(i, dp, ratings);
        }
        
        for(auto &&i : dp)
            cout << i << ' ';
        cout << endl;
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
    
    int check(int i, vector<int> &dp, const vector<int>& ratings) {
        if(i < 0 || i >= ratings.size()) return 0;
        if(dp[i]) return dp[i];
        
        bool l = i - 1 >= 0 && ratings[i] > ratings[i - 1];
        bool r = i + 1 < ratings.size() && ratings[i] > ratings[i + 1];
        
        if(l && r)
            dp[i] = max(check(i - 1, dp, ratings), check(i + 1, dp, ratings)) + 1;
        else if(l)
            dp[i] = check(i - 1, dp, ratings) + 1;
        else if(r)
            dp[i] = check(i + 1, dp, ratings) + 1;
        else
            dp[i] = 1;
        
        return dp[i];
    }   
};