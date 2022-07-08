// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<pair<long long, string>>> dp(n - 1, vector<pair<long long, string>>(n - 1, pair<long long, string>({0, ""})));
        for(int i = 0; i < n - 1; i++)
            dp[i][i].second = 'A' + i;
        
        for(int i = 0; i < n - 2; i++)
            dp[i][i + 1] = {p[i] * p[i + 1] * p[i + 2], string({'(', 'A' + i, 'A' + i + 1, ')'})};
        
        for(int step = 2; step < n - 1; step++)
        {
            for(int start = 0; start + step < n - 1; start++)
            {
                for(int cut = start; cut <= start + step - 1; cut++)
                {
                    if(dp[start][start + step].first == 0 || dp[start][cut].first + dp[cut + 1][start + step].first + p[start] * p[cut + 1] * p[start + step + 1] < dp[start][start + step].first)
                    {
                        dp[start][start + step].first = dp[start][cut].first + dp[cut + 1][start + step].first + p[start] * p[cut + 1] * p[start + step + 1];
                        dp[start][start + step].second = '(' + dp[start][cut].second + dp[cut + 1][start + step].second + ')';
                    }
                }
            }
        }
        // for(int i = 0; i < n-1;i++)
        //     cout << dp[0][i].second << endl;
        return dp[0][n - 2].second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends