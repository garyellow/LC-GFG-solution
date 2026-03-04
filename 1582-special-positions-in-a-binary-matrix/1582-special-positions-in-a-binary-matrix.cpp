class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> r(mat.size()), c(mat.front().size());

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.front().size(); j++) {
                if (mat[i][j]) {
                    r[i]++;
                    c[j]++;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            if (r[i] != 1)
                continue;
            for (int j = 0; j < mat.front().size(); j++) {
                if (mat[i][j] && mat[i][j] == c[j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};