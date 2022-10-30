class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> r = vector<vector<int>>(grid.size(), vector<int>(grid.front().size(), INT_MIN));
        r[0][0] = k;
        queue<pair<pair<int, int>, int>> bfs({{{0, 0}, k}});
        
        for(int step = 0; bfs.size(); step++) {
            for(int n = bfs.size(); n--;) {
                auto pos = bfs.front().first;
                auto re = bfs.front().second;
                bfs.pop();
                
                if(pos.first == grid.size() - 1 && pos.second == grid.front().size() - 1)
                    return step;
                
                if(pos.first - 1 >= 0 && re - grid[pos.first - 1][pos.second] > max(-1, r[pos.first - 1][pos.second]))
                    bfs.push({{pos.first - 1, pos.second}, r[pos.first - 1][pos.second] = re - grid[pos.first - 1][pos.second]});

                if(pos.second - 1 >= 0 && re - grid[pos.first][pos.second - 1] > max(-1, r[pos.first][pos.second - 1]))
                    bfs.push({{pos.first, pos.second - 1}, r[pos.first][pos.second - 1] = re - grid[pos.first][pos.second - 1]});

                if(pos.first + 1 < grid.size() && re - grid[pos.first + 1][pos.second] > max(-1, r[pos.first + 1][pos.second]))
                    bfs.push({{pos.first + 1, pos.second}, r[pos.first + 1][pos.second] = re - grid[pos.first + 1][pos.second]});

                if(pos.second + 1 < grid.front().size() && re - grid[pos.first][pos.second + 1] > max(-1, r[pos.first][pos.second + 1])) 
                    bfs.push({{pos.first, pos.second + 1}, r[pos.first][pos.second + 1] = re - grid[pos.first][pos.second + 1]});
            }
        }
        
        return -1;
    }
};