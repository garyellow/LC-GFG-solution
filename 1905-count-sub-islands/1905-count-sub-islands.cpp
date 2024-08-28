class UnionFind {
    vector<int> root, Size;

public:
    int merge;
    UnionFind(int N) : root(N), Size(N, 1), merge(0) {
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) { return x == root[x] ? x : root[x] = Find(root[x]); }

    bool Union(int x, int y) {
        x = Find(x), y = Find(y);

        if (x == y)
            return 0;

        if (Size[x] > Size[y]) {
            Size[x] += Size[y];
            root[y] = x;
        } else {
            Size[y] += Size[x];
            root[x] = y;
        }
        merge++;
        return 1;
    }
};

class Solution {
public:
    int r, c;
    inline int idx(int i, int j) { return i * c + j; }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r = grid1.size(), c = grid1[0].size();
        int N = r * c;
        UnionFind G(N + 1);
        int cntLand = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int curr = idx(i, j), down = idx(i + 1, j), right = idx(i, j + 1);
                bool g2 = grid2[i][j] == 1;
                cntLand += g2;
                if (g2) {
                    if (i + 1 < r && grid2[i + 1][j])
                        G.Union(curr, down);
                    if (grid1[i][j] == 0)
                        G.Union(curr, N);
                    if (j + 1 < c && grid2[i][j + 1])
                        G.Union(curr, right);
                }
            }
        }

        return cntLand - G.merge;
    }
};