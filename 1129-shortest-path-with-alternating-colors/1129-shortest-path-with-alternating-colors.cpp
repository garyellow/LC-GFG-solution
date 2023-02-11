class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> path(2, vector<vector<int>>(n));
        
        for(auto &&edge : redEdges) {
            path[1][edge.front()].push_back(edge.back());
        }
        
        
        for(auto &&edge : blueEdges) {
            path[0][edge.front()].push_back(edge.back());
        }
        
        vector<vector<bool>> is_gone(2, vector<bool>(n));
        is_gone.front().front() = true;
        is_gone.back().front() = true;
        
        queue<pair<int, bool>> bfs({{0, false}, {0, true}});
        vector<int> ans(n, -1);
        ans.front() = 0;
        
        for(int step = 1; bfs.size(); step++) {
            for(int n = bfs.size(); n--;) {
                auto [cur, red] = bfs.front();
                bfs.pop();
                
                for(auto &&edge : path[red][cur]) {
                    if(!is_gone[red][edge]) {
                        is_gone[red][edge] = true;
                        if(ans[edge] < 0) ans[edge] = step;
                        bfs.push({edge, !red});
                    }
                }
            }
        }
        
        return ans;
    }
};