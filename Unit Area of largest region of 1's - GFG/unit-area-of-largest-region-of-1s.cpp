//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int max_cnt = 0;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.front().size(); j++)
                if(grid[i][j] == 1)
                    max_cnt = max(max_cnt, go({i, j}, grid));
                
        return max_cnt;
    }
    
    int go(pair<int, int> point, vector<vector<int>>& grid)
    {
        int cnt = 1;
        
        grid[point.first][point.second] = 0;
        for(int x = -1; x <= 1; x++)
            for(int y = -1; y <= 1; y++)
                if(point.first + x >= 0 && point.second + y >= 0 && point.first + x < grid.size() && point.second + y < grid.front().size() && grid[point.first + x][point.second + y])
                    cnt += go({point.first + x, point.second + y}, grid);
                
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends