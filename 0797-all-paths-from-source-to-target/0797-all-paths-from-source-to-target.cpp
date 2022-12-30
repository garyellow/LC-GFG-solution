class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        find(graph, 0, vector<int>());
        
        return ans;
    }
    
    void find(const vector<vector<int>>& graph, const int x, vector<int> save) {
        save.push_back(x);
        
        if(x == graph.size() - 1)
            ans.push_back(save);
        else
            for(auto &&i : graph[x])
                find(graph, i, save);
    }
};