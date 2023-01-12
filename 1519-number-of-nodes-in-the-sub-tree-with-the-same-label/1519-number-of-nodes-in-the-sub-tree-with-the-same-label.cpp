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
        dfs(0, ans, is_gone, graph, labels);
        
        return ans;
    }
    
    vector<int> dfs(int cur, vector<int>& ans, vector<bool>& is_gone, vector<vector<int>>& graph, string& labels) {
        is_gone[cur] = true;
        vector<int> cnt(128);
        
        for(auto &&next : graph[cur]) {
            if(!is_gone[next]) {
                vector<int> temp = dfs(next, ans, is_gone, graph, labels);
                
                for(int i = 0; i < temp.size(); i++)
                    cnt[i] += temp[i];
            }
        }
        
        ans[cur] = ++cnt[labels[cur]];
        
        return cnt;
    }
};