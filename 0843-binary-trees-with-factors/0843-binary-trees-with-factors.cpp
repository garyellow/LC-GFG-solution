class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        unordered_map<int, long> dp;
        
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            
            for(int test = 0; test < i; test++)
                if(arr[i] % arr[test] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[test]] * dp[arr[i] / arr[test]]) % int(1e9 + 7);
            
            cnt = (cnt + dp[arr[i]]) % int(1e9 + 7);
        }
        
        return cnt;
    }
};