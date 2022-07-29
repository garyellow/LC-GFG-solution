//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPrime(int n)
    {
       if (n <= 1)
           return false;
       if (n == 2 || n == 3)
           return true;
       if (n % 2 == 0 || n % 3 == 0)
           return false;
       for (int i = 5; i <= sqrt(n); i = i + 6)
           if (n % i == 0 || n % (i + 2) == 0)
               return false;
    
       return true;
    }

    int firingEmployees(vector<int> &arr, int n){
        vector<vector<int>> line(n + 1);
        
        for(int i = 0; i < n; i++)
            line[arr[i]].push_back(i);
            
        queue<int> bfs({line[0].front()});
        
        int cnt = 0;
        for(int level = 0; bfs.size(); level++)
        {
            for(int n = bfs.size(); n--;)
            {
                if(level > 0 && isPrime(bfs.front() + 1 + level))
                    cnt++;
                
                for(auto &&i : line[bfs.front() + 1])
                    bfs.push(i);
                    
                bfs.pop();
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends