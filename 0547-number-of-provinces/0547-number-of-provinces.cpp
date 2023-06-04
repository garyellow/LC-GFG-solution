class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> u(isConnected.size());
        iota(u.begin(), u.end(), 0);
        
        for(int i = 0; i < isConnected.size(); i++)
            for(int j = 0; j < isConnected.size(); j++)
                if(isConnected[i][j])
                    u[find(i, u)] = find(j, u);
        
        unordered_set<int> s;
        
        for(auto &&p : u) 
            s.insert(find(p, u));
        
        return s.size();
    }
    
    int find(int val, vector<int> &u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};