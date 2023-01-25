class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dis) {
        for(int dist = 0; node != -1 && dis[node] == -1; node = edges[node]) {
            dis[node] = dist++;
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1, min_dist = INT_MAX, n = edges.size();
        
        vector<int> dist1(n, -1), dist2(n, -1);
        dfs(node1, edges, dist1);
        dfs(node2, edges, dist2);

        for (int i = 0; i < n; ++i) {
            if (min(dist1[i], dist2[i]) >= 0 && max(dist1[i], dist2[i]) < min_dist) {
                min_dist = max(dist1[i], dist2[i]);
                res = i;
            }
        }
        
        return res;
    }
};