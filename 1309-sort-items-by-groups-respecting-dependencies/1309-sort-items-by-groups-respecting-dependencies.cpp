class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0; i < n; i++){
            if (group[i] == -1) group[i] = m++;
        }
        vector<vector<int>> adj_group(m), adj_item(n);
        vector<int> deg_group(m), deg_item(n);
        for(int i = 0; i < n; i++){
            int to_i = group[i];
            for(auto &&from : beforeItems[i]){
                int from_j = group[from];
                if(to_i != from_j){
                    adj_group[from_j].push_back(to_i);
                    deg_group[to_i]++;
                }
                adj_item[from].push_back(i);
                deg_item[i]++;
            }
        }
        vector<int> sort_group=helper(adj_group, deg_group, m);
        vector<int> sort_item=helper(adj_item, deg_item, n); 
        if (sort_group.empty() || sort_item.empty()) return {};

        vector<vector<int>> item_gp(m);
        for(auto &&i : sort_item)
            item_gp[group[i]].push_back(i);
        
        vector<int> ans;
        for(auto &&i : sort_group) {
            for(auto &&item : item_gp[i]) {
                ans.push_back(item);
            }
        }
        
        return ans;
    }

    vector<int> helper( vector<vector<int>>& adj, vector<int>& deg, int sz)
    {
        vector<int> res;
        function<void(int)> dfs = [&](int i) {
            res.push_back(i);
            deg[i] = -1;
            for(auto &&j: adj[i]) {
                if (--deg[j] == 0) dfs(j);
            }
        };
                
        for(int i = 0; i < sz; i++) {
            if (deg[i] == 0) dfs(i);
        }
        for(int i = 0; i < sz; i++) {
            if(deg[i] > 0) return {};
        }
        return res;
    }
};