class Solution {
public:
    int numberOfArrays(string &s, int k) {
        vector<long long> dp(s.size() + 1, 0);
        dp.back() = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0')  continue;

            long long num = 0;
            int j = i;
            while (j < s.size()) {
                string temp = s.substr(i, j - i + 1);
                if(temp.size() > 10 || temp.size() == 10 && temp.front() != '1') break;
                
                int x = stoi(temp);
                if (x > k)  break;
                
                num += dp[j + 1];
                    
                j++;
            }
            dp[i] = num % int(1e9 + 7);
        }
        
        return dp[0];
    }
};