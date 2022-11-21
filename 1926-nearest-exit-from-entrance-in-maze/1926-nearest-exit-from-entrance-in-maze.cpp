class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> bfs({{entrance[0] - 1, entrance[1]}, {entrance[0] + 1, entrance[1]}, {entrance[0], entrance[1] - 1}, {entrance[0], entrance[1] + 1}});
        maze[entrance[0]][entrance[1]] = '+';
        
        for(int step = 1; bfs.size(); step++)
        {
            for(int n = bfs.size(); n--;)
            {
                auto temp = bfs.front();
                bfs.pop();  
                
                if(temp.front() < 0 || temp.back() < 0 || temp.front() >= maze.size() || temp.back() >= maze.front().size() || maze[temp[0]][temp[1]] == '+')
                    continue;
                
                if(temp.front() == 0 || temp.back() == 0 || temp.front() == maze.size() - 1 || temp.back() == maze.front().size() - 1)
                    return step;
                else
                {
                    maze[temp[0]][temp[1]] = '+';
                    bfs.push({temp.front() - 1, temp.back()});
                    bfs.push({temp.front() + 1, temp.back()});
                    bfs.push({temp.front(), temp.back() - 1});
                    bfs.push({temp.front(), temp.back() + 1});
                }
            }
        }
        
        return -1;
    }
};