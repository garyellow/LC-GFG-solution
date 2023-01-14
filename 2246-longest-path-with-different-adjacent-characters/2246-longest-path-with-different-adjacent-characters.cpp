class Solution {
public:
    int longestPath(vector<int>& parent, string& s) {
        vector<vector<int>> graph(parent.size());
        
        for(int i = 1; i < parent.size(); i++)
            graph[parent[i]].push_back(i);
        
        int ans = 1;
        dfs(s, 0, ans, graph);
        
        return ans;
    }
    
    int dfs(string &s, int cur, int& ans, vector<vector<int>>& graph)
    {
        int mx1 = 0, mx2 = 0;
        for(auto &&next : graph[cur])
        {
            int len = dfs(s, next, ans, graph);
            ans = max(ans, len);
            
            if(s[cur] == s[next]) continue;
            
            if(len > mx1) {
                mx2 = mx1;
                mx1 = len;
            }
            else mx2 = max(mx2, len);
        }
        
        ans = max(ans, 1 + mx1 + mx2);
        
        return 1 + mx1;
    }
};