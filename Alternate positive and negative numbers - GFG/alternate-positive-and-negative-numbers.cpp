//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    queue<int> positive, negative;
	    
	    for(int i = 0; i < n; i++)
	        if(arr[i] < 0) negative.push(arr[i]);
	        else positive.push(arr[i]);
	    
	    int index = 0;
	    while(positive.size() && negative.size())
	    {
	        arr[index++] = positive.front();
	        positive.pop();
	        
	        arr[index++] = negative.front();
	        negative.pop();
	    }
	    
	    while(positive.size())
	    {
	        arr[index++] = positive.front();
	        positive.pop();
	    }
	    
	    while(negative.size())
	    {
	        arr[index++] = negative.front();
	        negative.pop();
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends