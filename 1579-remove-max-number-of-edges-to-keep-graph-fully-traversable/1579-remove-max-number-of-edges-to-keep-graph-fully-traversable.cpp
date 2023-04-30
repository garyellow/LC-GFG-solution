class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> ua(n + 1), ub(n + 1);
        iota(ua.begin(), ua.end(), 0);
        iota(ub.begin(), ub.end(), 0);
        
        sort(edges.rbegin(), edges.rend());
        
        int r = 0, a = 0, b = 0;
        for(auto &&edge : edges) {
            if(edge[0] == 3) {
                if(find(edge[1], ua) != find(edge[2], ua)) {
                    ua[find(edge[1], ua)] = find(edge[2], ua);
                    ub[find(edge[1], ub)] = find(edge[2], ub);
                    a++;
                    b++;
                }
                else r++;
            }
            else if(edge[0] == 1) {
                if(find(edge[1], ua) != find(edge[2], ua)) {
                    ua[find(edge[1], ua)] = find(edge[2], ua);
                    a++;
                }
                else r++;
            }
            else {
                if(find(edge[1], ub) != find(edge[2], ub)){
                    ub[find(edge[1], ub)] = find(edge[2], ub);
                    b++;
                }
                else r++;
            }
        }

        return (a == n - 1 && b == n - 1) ? r : -1;
    }
    
    inline int find(int val, vector<int> &u) {
        return u[val] == val ? val : u[val] = find(u[val], u);
    }
};