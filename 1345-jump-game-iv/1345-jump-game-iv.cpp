class Solution
{
public:
    queue<int> bfs = queue<int>({0});
    map<int, vector<int>> gate;
    vector<bool> Is_gone = vector<bool>({true});

    int minJumps(vector<int> &arr) {
        Is_gone.resize(arr.size());

        for (int i = 0; i < arr.size(); i++)
            gate[arr[i]].push_back(i);

        for (int cnt = 1; arr.size() > 1; cnt++) {
            queue<int> temp = bfs;

            while (temp.size()) {
                int index = temp.front();
                temp.pop();
                bfs.pop();
                
                if(index - 1 >= 0 && !Is_gone[index - 1])
                    bfs_push(index - 1, bfs);

                if(index + 1 < arr.size())
                    bfs_push(index + 1, bfs);

                if(gate.count(arr[index])) {
                    for(auto &&i : gate[arr[index]])
                        bfs_push(i, bfs);
                    gate.erase(arr[index]);
                }

                if(Is_gone[arr.size() - 1]) return cnt;
            }
        }

        return 0;
    }

    void bfs_push(const int &num, queue<int> &bfs) {
        if (!Is_gone[num]) {
            bfs.push(num);
            Is_gone[num] = true;
        }
    }
};