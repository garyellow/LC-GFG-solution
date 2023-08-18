class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n, vector<int>());

        for(auto &&road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        int m = 0;
        vector<int> can;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].size() > m) {
                m = graph[i].size();
                can = vector<int>();
            }

            if(graph[i].size() == m) {
                can.push_back(i);
            }
        }

        int ans = 0;
        for(int i = 0; i < graph.size(); i++) {
            for(int j = i + 1; j < graph.size(); j++) {
                int temp = graph[i].size() + graph[j].size();
                for(int k = 0; k < graph[i].size(); k++) {
                    if(graph[i][k] == j) {
                        temp--;
                        k = graph[i].size();
                    }
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};