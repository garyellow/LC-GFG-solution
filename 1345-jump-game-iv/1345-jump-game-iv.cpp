class Solution {
public:
    queue<int> bfs = queue<int>({0});
    unordered_map<int, vector<int>> gate;
    vector<bool> isGone = vector<bool>({true});

    int minJumps(vector<int>& arr) {
        isGone.resize(arr.size());

        for (int i = 0; i < arr.size(); i++)
            gate[arr[i]].push_back(i);

        for (int cnt = 1; arr.size() > 1; cnt++) {
            queue<int> temp = bfs;

            while (temp.size()) {
                int index = temp.front();
                temp.pop();
                bfs.pop();

                if (index - 1 >= 0 && !isGone[index - 1]) {
                    if (!isGone[index - 1]) {
                        bfs.push(index - 1);
                        isGone[index - 1] = true;
                    }
                }

                if (index + 1 < arr.size()) {
                    if (!isGone[index + 1]) {
                        bfs.push(index + 1);
                        isGone[index + 1] = true;
                    }
                }

                if (gate.count(arr[index])) {
                    for (auto i : gate[arr[index]]) {
                        if (!isGone[i]) {
                            bfs.push(i);
                            isGone[i] = true;
                        }
                    }

                    gate.erase(arr[index]);
                }

                if (isGone[arr.size() - 1])
                    return cnt;
            }
        }

        return 0;
    }
};