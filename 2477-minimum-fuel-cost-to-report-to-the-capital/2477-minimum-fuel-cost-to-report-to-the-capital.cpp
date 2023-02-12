class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size() + 1);
        for(auto &&road : roads) {
            graph[road.front()].push_back(road.back());
            graph[road.back()].push_back(road.front());
        }
        
        long long ans = 0;
        dfs(graph, 0, -1, seats, ans);
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& graph, int u, int prev, int seats, long long& ans) {
        int people = 1;
        for (auto &&v : graph[u]) {
            if (v == prev)
                continue;
            
            people += dfs(graph, v, u, seats, ans);
        }
        
        if (u > 0)
            ans += (long long)(ceil(1.f * people / seats));
        
        return people;  
    }
};