class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> bfs({{entrance[0] - 1, entrance[1]}, {entrance[0] + 1, entrance[1]}, {entrance[0], entrance[1] - 1}, {entrance[0], entrance[1] + 1}});
        maze[entrance[0]][entrance[1]] = '+';
        
        for(int step = 1; bfs.size(); step++)
        {
            for(int n = bfs.size(); n--;)
            {
                auto temp = bfs.front();
                bfs.pop();  
                
                if(temp.first < 0 || temp.second < 0 || temp.first >= maze.size() || temp.second >= maze.front().size() || maze[temp.first][temp.second] == '+')
                    continue;
                
                if(temp.first == 0 || temp.second == 0 || temp.first == maze.size() - 1 || temp.second == maze.front().size() - 1)
                    return step;
                else
                {
                    maze[temp.first][temp.second] = '+';
                    bfs.push({temp.first - 1, temp.second});
                    bfs.push({temp.first + 1, temp.second});
                    bfs.push({temp.first, temp.second - 1});
                    bfs.push({temp.first, temp.second + 1});
                }
            }
        }
        
        return -1;
    }
};