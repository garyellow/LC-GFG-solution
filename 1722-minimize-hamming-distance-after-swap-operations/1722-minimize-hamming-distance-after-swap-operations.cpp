class Solution {
public:
    vector<int> parent;

    int find(int x) {
        return parent[x] == x ? parent[x] : parent[x] = find(parent[x]);
    }

    void make_union(int a, int b) { parent[find(a)] = find(b); }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto& swap : allowedSwaps) {
            make_union(swap[0], swap[1]);
        }

        // Group source values by their component root
        unordered_map<int, unordered_map<int, int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)][source[i]]++;
        }

        int hammingDist = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto& freq = groups[root];
            if (freq.count(target[i]) && freq[target[i]] > 0) {
                freq[target[i]]--;
            } else {
                hammingDist++;
            }
        }

        return hammingDist;
    }
};