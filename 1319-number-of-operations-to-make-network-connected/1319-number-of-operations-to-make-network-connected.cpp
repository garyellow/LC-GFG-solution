class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        
        vector<int> u(n);
        for(int i = 0; i < u.size(); i++) u[i] = i;
        
        for(auto &&c : connections) u[find(c[0], u)] = find(c[1], u);
        
        set<int> cnt;
        for(int i = 0; i < u.size(); i++) cnt.insert(find(i, u));
        
        return cnt.size() - 1;
    }
    
    inline int find(int val, vector<int> &u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};