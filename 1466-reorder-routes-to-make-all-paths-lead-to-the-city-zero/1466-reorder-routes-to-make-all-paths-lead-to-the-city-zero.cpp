class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<bool> isGone(n);
        
        for(auto &&c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        vector<vector<int>> correct;
        
        queue<int> bfs({0});
        isGone[0] = true;
        
        while(bfs.size()) {
            int cur = bfs.front();
            bfs.pop();
            
            isGone[cur] = true;
            
            for(auto &&next : graph[cur]) {
                if(!isGone[next]) {
                    correct.push_back({next, cur});
                    bfs.push(next);
                }
            }
        }
        
        sort(connections.begin(), connections.end());
        sort(correct.begin(), correct.end());
        
        vector<vector<int>> temp(n);
        auto it = set_difference(connections.begin(), connections.end(), correct.begin(), correct.end(), temp.begin());
        
        return it - temp.begin();
    }
};