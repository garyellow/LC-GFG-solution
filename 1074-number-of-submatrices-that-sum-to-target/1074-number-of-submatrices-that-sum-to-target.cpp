class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 1; j < matrix.front().size() ; j++)
                matrix[i][j] += matrix[i][j - 1];
        
        int cnt = 0;
        for(int js = 0; js < matrix.front().size(); js++)
        {
            for(int je = js; je < matrix.front().size(); je++)
            {
                int sum = 0;
                map<int, int> dp({{0 ,1}});
                
                for(int i = 0; i < matrix.size(); i++)
                {
                    sum += matrix[i][je] - (js > 0 ? matrix[i][js - 1] : 0);
                    cnt += dp[sum - target];
                    dp[sum]++;
                }
            }
        }
        
        
        return cnt;
    }
};