class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> losers(n);

        for (auto& edge : edges) {
            losers[edge[1]] = true;
        }

        int candidate = -1;
        for (int i = 0; i < losers.size(); i++) {
            if (!losers[i]) {
                if (candidate == -1) {
                    candidate = i;
                }
                else {
                    return -1;
                }
            }
        }

        return candidate;
    }
};