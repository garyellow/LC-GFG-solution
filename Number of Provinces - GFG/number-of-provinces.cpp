//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> u(V);
        iota(u.begin(), u.end(), 0);
        
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(i!=j && adj[i][j])
                    u[find(j, u)] = find(i, u);
        
        set<int> ans;
        for(auto &&i : u)
            ans.insert(find(i, u));
            
        return ans.size();
    }
    
    int find(int i, vector<int> &u)
    {
        return u[i] == i ? i : u[i] = find(u[i], u);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends