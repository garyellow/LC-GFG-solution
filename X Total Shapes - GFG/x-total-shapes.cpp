//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.front().size(); j++)
            {
                if(grid[i][j] == 'X')
                {
                    cnt++;
                    
                    queue<pair<int,int>> bfs({{i, j}});
                    while(bfs.size())
                    {
                        auto temp = bfs.front();
                        bfs.pop();
                        
                        grid[temp.first][temp.second] = 'O';
                        
                        if(temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == 'X') bfs.push({temp.first - 1, temp.second});
                        if(temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == 'X') bfs.push({temp.first, temp.second - 1});
                        if(temp.first + 1 < grid.size() && grid[temp.first + 1][temp.second] == 'X') bfs.push({temp.first + 1, temp.second});
                        if(temp.second + 1 < grid.front().size() && grid[temp.first][temp.second + 1] == 'X') bfs.push({temp.first, temp.second + 1});
                    }
                }
            }
            
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends