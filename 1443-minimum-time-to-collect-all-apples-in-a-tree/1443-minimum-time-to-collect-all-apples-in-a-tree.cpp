class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        vector<bool> is_gone(n, false);
        
        for(auto &&edge : edges) {
            graph[edge.front()].push_back(edge.back());
            graph[edge.back()].push_back(edge.front());
        }
        
        return max(0, get_apple(0, is_gone, hasApple, graph) - 2);
    }
    
    int get_apple(int cur, vector<bool>& is_gone, vector<bool>& hasApple, unordered_map<int, vector<int>>& graph) {
        is_gone[cur] = true;
        
        int cnt = 0;
        for(auto &&next : graph[cur]) {
            if(!is_gone[next]) {
                cnt += get_apple(next, is_gone, hasApple, graph);
            }
        }
        
        // cout << cur << ' ' << hasApple[cur] << ' ' << cnt << endl;
        
        bool check = (hasApple[cur] || cnt);
        
        return cnt + check * 2;
    }
};