class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int k = 26;
        vector<int> indegrees(colors.size(), 0);
        vector<vector<int>> graph(colors.size(), vector<int>());
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indegrees[v]++;
        }
        unordered_set<int> zero_indegree;
        for (int i = 0; i < colors.size(); i++) {
            if (indegrees[i] == 0) {
                zero_indegree.insert(i);
            }
        }
        vector<vector<int>> counts(colors.size(), vector<int>(k, 0));
        for (int i = 0; i < colors.size(); i++) {
            counts[i][colors[i] - 'a']++;
        }
        int max_count = 0;
        int visited = 0;
        while (!zero_indegree.empty()) {
            int u = *zero_indegree.begin();
            zero_indegree.erase(u);
            visited++;
            for (int v : graph[u]) {
                for (int i = 0; i < k; i++) {
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                }
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    zero_indegree.insert(v);
                }
            }
            max_count = max(max_count, *max_element(counts[u].begin(), counts[u].end()));
        }
        return visited == colors.size() ? max_count : -1;
    }
};