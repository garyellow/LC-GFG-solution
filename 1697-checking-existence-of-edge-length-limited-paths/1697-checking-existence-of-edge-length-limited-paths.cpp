class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        
        for (int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        
        vector<int> u(n);
        iota(u.begin(), u.end(), 0);
        
        int i = 0;
        for (auto &&q : queries) { 
            int x = q[0], y = q[1], limit = q[2], qid = q[3];
            for (; i < edgeList.size() && edgeList[i][2] < limit; i++) 
                u[find(edgeList[i][0], u)] = find(edgeList[i][1], u);
            
            ans[qid] = find(x, u) == find(y, u);
        }
        
        return ans;
    }
    
    int find(int val, vector<int> &u) {
        return u[val] == val ? val : u[val] = find(u[val], u);
    }
};