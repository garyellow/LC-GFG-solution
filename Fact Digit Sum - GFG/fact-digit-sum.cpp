//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    static vector<int> dp;
	public:
	Solution() {
	    if(dp.empty()) {
	        dp.push_back(1);
	        
	        long x = dp.back();
	        for(int i = 1; i <= 9; x *= ++i)
	            dp.push_back(x);
	    }
	}
	
	vector<int> FactDigit(int N)
	{
	    int n = dp.size();
	    
	    vector<int> ans;
	    for(int cur = n - 1; N > 0;)
	    {
	        if(dp[cur] <= N)
	        {
	            N -= dp[cur];
	            ans.push_back(cur);
	        }
	        else
	            cur--;
	    }
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};

vector<int> Solution::dp;

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends