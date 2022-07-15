// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++)
            pq.push(arr[i]);
        
        long long int sum = 0;
        if(pq.size() & 1) {
            sum = pq.top();
            pq.pop();
        }
        
        while(pq.size())
        {
            sum *= 10;
            sum += pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends