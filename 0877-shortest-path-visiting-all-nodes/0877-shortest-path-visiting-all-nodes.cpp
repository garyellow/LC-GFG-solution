class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        queue<pair<int, bitset<12>>> bfs;
        set<pair<int, size_t>> check;
        hash<bitset<12>> hash;

        for (short i = 0; i < graph.size(); i++) {
            bfs.push({i, bitset<12>().set(i)});
            check.insert({i, hash(bitset<12>().set(i))});
        }

        for (int cnt = 1; !bfs.empty(); cnt++) {
            for (int len = bfs.size(); len--;) {
                auto temp = bfs.front();
                bfs.pop();  
                for (auto &&i : graph[temp.first]) {
                    auto now = temp.second;
                    now.set(i);

                    if (now.count() == graph.size()) return cnt;
                    else if (check.count({i, hash(now)}) == 0) {
                        bfs .push({i, now});
                        check.insert({i, hash(now)});
                    }
                }
            }
        }

        return 0;
    }
};