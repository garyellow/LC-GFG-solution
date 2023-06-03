class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < n; i++) {
            if(i != headID) {
                graph[manager[i]].push_back(i);
            }
        }
        
        return inform(headID, informTime, graph);
    }
    
    int inform(int cur, vector<int>& informTime, vector<vector<int>> &graph) {
        int cnt = informTime[cur];
        
        for(auto &&next : graph[cur]) {
            cnt = max(cnt, informTime[cur] + inform(next, informTime, graph));
        }
        
        return cnt;
    }
};