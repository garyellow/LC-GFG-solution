class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> u(n + 1);
        vector<int> m(n + 1, INT_MAX);
        for(int i = 0; i <= n; i++) u[i] = i;
        
        
        for(auto &&road : roads) {
            u[find(road[0], u)] = find(road[1], u);
            m[road[0]] = min(m[road[0]], road[2]);
            m[road[1]] = min(m[road[1]], road[2]);
        }
        
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++)
            if(find(i, u) == find(n, u))
                ans = min(ans, m[i]);
        
        return ans;
    }
    
    inline int find(int x, vector<int> &u) {
        return x == u[x] ? x : u[x] = find(u[x], u);
    }
};