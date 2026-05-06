class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> rbox(box.front().size(), vector<char>(box.size()));

        for (int i = 0; i < box.size(); i++) {
            int u = box[i].size() - 1, d = box[i].size() - 1;

            while (u >= 0) {
                if (box[i][u] == '*') {
                    rbox[u][box.size() - 1 - i] = '*';
                    while (d > u) {
                        rbox[d--][box.size() - 1 - i] = '.';
                    }
                    u--, d--;
                } else if (box[i][u] == '#') {
                    rbox[d][box.size() - 1 - i] = '#';
                    u--, d--;
                } else {
                    u--;
                }
            }

            while (d > u) {
                rbox[d--][box.size() - 1 - i] = '.';
            }
        }

        return rbox;
    }
};