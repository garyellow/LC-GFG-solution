class Solution {
public:
    vector<int> u;
    bool isBipartite(vector<vector<int>>& graph) {
        u.resize(graph.size());
        iota(u.begin(), u.end(), 0);
        int zero = 0;
        for(auto &&points : graph) {
            if(points.empty()) zero++;
            for(auto &&point : points) u[find(point)] = find(points.front());
        }
        
        
        unordered_set<int> cnt;
        for(auto &&i : u) cnt.insert(find(i));
        
        for(auto &&i : cnt)
            if(graph[i].size() && find(graph[i].front()) == i)
                return false;

        return !((cnt.size() - zero) % 2);
    }
    
    int find(int val) {
        return u[val] == val ? val : u[val] = find(u[val]);
    }
};