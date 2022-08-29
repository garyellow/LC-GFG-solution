class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.front().size(); j++)
                if(grid[i][j] == '1')
                {
                    cnt++;
                    go({i, j}, grid);
                }
                
        return cnt;
    }
    
    void go(pair<int, int> point, vector<vector<char>>& grid)
    {
        grid[point.first][point.second] = '0';
        if(point.first - 1 >= 0 && grid[point.first - 1][point.second] == '1') go({point.first - 1, point.second}, grid);
        if(point.second - 1 >= 0 && grid[point.first][point.second - 1] == '1') go({point.first, point.second - 1}, grid);
        if(point.first + 1 < grid.size() && grid[point.first + 1][point.second] == '1') go({point.first + 1, point.second}, grid);
        if(point.second + 1 < grid.front().size() && grid[point.first][point.second + 1] == '1') go({point.first, point.second + 1}, grid);
    }
};