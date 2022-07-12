// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string S, string T) {
        vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1));
        for(int i = 1; i <= S.size(); i++)
            dp[i][0] = 1;
        
        for(int i = 0; i <= T.size(); i++)
            dp[0][i] = 1e3;
        
        for(int i = 1; i <= S.size(); i++)
        {
            for(int j = 1; j <= T.size(); j++)
            {
                int k;
                for(k = j - 1; k >= 0; k--)
                    if(T[k] == S[i - 1])
                        break;
                        
                if(k < 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][k]);
            }
        }
        
        return dp.back().back() >= 1e3 ? -1 : dp.back().back();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends