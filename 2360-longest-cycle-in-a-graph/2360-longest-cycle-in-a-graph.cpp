class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int ans = -1;
        
        vector<pair<int, int>> isGone(edges.size(), {-1, -1});
        for(int i = 0; i < edges.size(); i++) {
            if(isGone[i] == pair<int, int>({ -1, -1 }))
                ans = max(ans, dfs(i, i, 0, isGone, edges));
        }
        
        return ans;
    }
    
    int dfs(int ori, int cur, int path, vector<pair<int, int>> &isGone, vector<int> &edges) {
        if(isGone[cur].second != -1) return path - isGone[cur].second;
        
        isGone[cur] = { ori, path };
        
        if(edges[cur] != -1 && (isGone[edges[cur]].first == -1 || isGone[edges[cur]].first == ori)) return dfs(ori, edges[cur], ++path, isGone, edges);
        else return -1;
    }
}; 