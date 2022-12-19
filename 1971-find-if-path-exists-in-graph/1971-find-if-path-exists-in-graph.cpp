class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> u;
        for(int i = 0; i < n; i++) 
            u.push_back(i);
        
        for(auto &&edge : edges) {
            u[find(edge.front(), u)] = find(edge.back(), u);
        }
        
        return find(source, u) == find(destination, u);
    }
    
    int find(int val, vector<int> &u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};