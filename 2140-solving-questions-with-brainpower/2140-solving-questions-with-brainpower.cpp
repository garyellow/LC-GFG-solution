class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size());
        
        return check(0, dp, questions);
    }
    
    long long check(int question, vector<long long> &dp, vector<vector<int>>& questions) {
        if(question >= questions.size()) return 0;
        else if(!dp[question]) {
            dp[question] = max(check(question + 1, dp, questions), questions[question][0] + check(question + questions[question][1] + 1, dp, questions));
        }
        
        return dp[question]; 
    }
}; 