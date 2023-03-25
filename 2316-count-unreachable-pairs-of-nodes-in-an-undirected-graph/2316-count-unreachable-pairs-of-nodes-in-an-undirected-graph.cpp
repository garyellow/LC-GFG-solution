class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> u(n);
        
        for(int i = 0; i < n; i++) u[i] = i;
        
        for(auto &&edge : edges) u[find(edge[0], u)] = find(edge[1], u);
        
        map<int, int> cnt;
        
        for(auto &&i : u) cnt[find(i, u)]++;
        
        long long s = accumulate(cnt.begin(), cnt.end(), 0, [](int &sum, auto &cur) { return sum + cur.second;});
        
        long long ans = accumulate(cnt.begin(), cnt.end(), 0LL, [&](auto &sum, auto &cur) { return sum + cur.second * (s - cur.second);});
        
        return ans / 2;
    }
    
    int find(int val, vector<int> &u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};