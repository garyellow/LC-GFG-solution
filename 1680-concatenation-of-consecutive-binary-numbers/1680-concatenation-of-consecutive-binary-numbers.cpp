class Solution {
public:
    static vector<int> ans;
    
    Solution() {
        if(ans.empty())
        {
            long temp = 0, MOD = 1e9 + 7;
            ans.push_back(temp);
        
            for (int i = 1; i <= 1e5; i++)
            {
                int len = log2(i) + 1;
                ans.push_back(temp = ((temp << len) % MOD + i) % MOD);
            }
        }
    }
    
    int concatenatedBinary(int n) {
        return ans[n];
    }
};

vector<int> Solution::ans;