class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string& labels) {
        vector<vector<int>> graph(n);
        vector<bool> is_gone(n, false);
        
        for(auto &&edge : edges) {
            graph[edge.front()].push_back(edge.back());
            graph[edge.back()].push_back(edge.front());
        }
        
        vector<int> ans(n);
        dfs(0, -1, ans, graph, labels);
        
        return ans;
    }
    
    vector<int> dfs(int cur, int last, vector<int>& ans, vector<vector<int>>& graph, string& labels) {
        vector<int> cnt(128);
        
        for(auto &&next : graph[cur]) {
            if(next != last) {
                vector<int> temp = dfs(next, cur, ans, graph, labels);
                
                for(int i = 0; i < temp.size(); i++)
                    cnt[i] += temp[i];
            }
        }
        
        ans[cur] = ++cnt[labels[cur]];
        
        return cnt;
    }
};