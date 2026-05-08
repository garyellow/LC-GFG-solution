class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *ranges::max_element(nums);

        vector<bool> prime(mx + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i <= mx; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<vector<int>> pos(mx + 1);
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> visited(n);
        visited[0] = true;
        while (!q.empty()) {
            auto [i, t] = q.front();
            q.pop();

            if (i == n - 1)
                return t;

            if (i > 0 && !visited[i - 1]) {
                q.push({i - 1, t + 1});
                visited[i - 1] = true;
            }
            if (i < n - 1 && !visited[i + 1]) {
                q.push({i + 1, t + 1});
                visited[i + 1] = true;
            }

            if (prime[nums[i]]) {
                int p = nums[i];
                for (int m = p; m <= mx; m += p) {
                    for (auto j : pos[m]) {
                        if (!visited[j]) {
                            q.push({j, t + 1});
                            visited[j] = true;
                        }
                    }
                    pos[m].clear();
                }
                prime[p] = false;
            }
        }

        return n - 1;
    }
};