// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	unordered_map<int, int> record;
    bool brainGame(vector<int> nums) {
        int count = 0;
        for(auto &&num : nums) {
            int temp = primeFactors(num);
            if(temp) count ^= temp - 1;
        }
        
        return count != 0;
    }
    
    int primeFactors(int num)
    {
        int ans = 0;
        int n = num;
        for(int i = 2; i <= num / 2; i++)
        {
            while(n % i == 0)
            {
                ans++;
                n /= i;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends