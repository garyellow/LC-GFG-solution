//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    static vector<int> dp;
    Solution() {
        if(dp.empty())
        {
            dp.push_back(0);
            dp.push_back(1);
            dp.push_back(2);
            
            for(int x = 3; x <= 1e4; x++)
                dp.push_back((dp[x - 1] + 1LL * (x - 1) * dp[x - 2]) % int(1e9 + 7));
        }
    }

    int countFriendsPairings(int n) 
    {
        return int(dp[n]);
    }
};    

vector<int> Solution::dp;
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends