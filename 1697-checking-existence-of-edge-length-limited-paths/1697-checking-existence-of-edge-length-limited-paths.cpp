class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        parent[x] = y;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int find(int a) {
        return parent[a] == a ? a : (parent[a] = find(parent[a]));
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        
        for (int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        
        UnionFind uf(n);
        
        int i = 0;
        for (auto &&q : queries) { 
            int x = q[0], y = q[1], limit = q[2], qid = q[3];
            for (; i < edgeList.size() && edgeList[i][2] < limit; i++) 
                uf.connect(edgeList[i][0], edgeList[i][1]);
            
            ans[qid] = uf.connected(x, y);
        }
        return ans;
    }
    
    int find(int val, vector<int> &u) {
        return u[val] == val ? val : u[val] = find(u[val], u);
    }
};