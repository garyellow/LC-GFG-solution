struct bfs {
    int x;
    int y;
    unordered_set<char> key;
    int length;
};

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        max_i = grid.size();
        max_j = grid.front().size();
        go_map = vector<vector<short>>(max_i, vector<short>(max_j));
        bfs temp;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (islower(grid[i][j])) {
                    key_map[{i, j}] = toupper(grid[i][j]);
                    key_nums++;
                }

                if (isupper(grid[i][j])) {
                    lock_map[{i, j}] = grid[i][j];
                    go_map[i][j] = 1;
                }

                if (grid[i][j] == '@') {
                    temp.x = i;
                    temp.y = j;
                }

                if (grid[i][j] == '#')
                    go_map[i][j] = 1;
            }
        }

        temp.key.clear();
        temp.length = 0;
        BFS.push(temp);

        while (!BFS.empty())
        {
            temp = BFS.front();
            BFS.pop();

            if (key_map.count({temp.x, temp.y}))
                temp.key.insert(key_map[{temp.x, temp.y}]);

            if (temp.key.size() == key_nums)
                return temp.length;

            temp.length++;

            bfs now;
            if (check_cango(temp.x + 1, temp.y, temp.key)) {
                now = temp;
                now.x += 1;
                if(visited.count(hash(now)) == 0) {
                    BFS.push(now);
                    visited.insert(hash(now));
                }
            }

            if (check_cango(temp.x - 1, temp.y, temp.key)) {
                now = temp;
                now.x -= 1;
                if(visited.count(hash(now)) == 0) {
                    BFS.push(now);
                    visited.insert(hash(now));
                }
            }

            if (check_cango(temp.x, temp.y + 1, temp.key)) {
                now = temp;
                now.y += 1;
                if(visited.count(hash(now)) == 0) {
                    BFS.push(now);
                    visited.insert(hash(now));
                }
            }

            if (check_cango(temp.x, temp.y - 1, temp.key)) {
                now = temp;
                now.y -= 1;
                if(visited.count(hash(now)) == 0) {
                    BFS.push(now);
                    visited.insert(hash(now));
                }
            }
        }

        return -1;
    }

    bool check_cango(int x, int y, unordered_set<char> &key) {
        if (x < 0 || x >= max_i)
            return false;
        if (y < 0 || y >= max_j)
            return false;

        if (lock_map.count({x, y}) > 0)
            return key.count(lock_map[{x, y}]) > 0;

        return go_map[x][y] != 1;
    }

    unsigned long hash(bfs &temp) {
        unsigned long num = 0;
        num += temp.x;
        num += temp.y * 100;

        for(const auto &i : temp.key)
            num += 10000 * pow(2, i - 'A');

        return num;
    }

    queue<bfs> BFS;
    vector<vector<short>> go_map;
    map<pair<int, int>, char> key_map;
    map<pair<int, int>, char> lock_map;
    set<unsigned long> visited;

    int key_nums = 0;
    int max_i, max_j;
};
