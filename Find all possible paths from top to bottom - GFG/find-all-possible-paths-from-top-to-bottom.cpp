// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> temp;
        DFS(0, 0, temp, grid);
        return ans;
    }
    
    void DFS(int i, int j, vector<int> &temp, const vector<vector<int>> &grid)
    {
        try
        {
            temp.push_back(grid.at(i).at(j));
        }
        catch(exception)
        {
            return;
        }
        
        if(temp.back() == grid.back().back())
            ans.push_back(temp);
        
        DFS(i + 1, j, temp, grid);
        DFS(i, j + 1, temp, grid);
        
        temp.pop_back();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends