class Solution {
public:
    vector<bool> already;

    bool canReach(vector<int>& arr, int start) {
        already = vector<bool>(arr.size());

        return dfs(arr, start);
    }

    bool dfs(const vector<int>& arr, const int& now) {
        if (now < 0 || now >= arr.size() || already[now])
            return false;

        already[now] = true;

        if (arr[now] == 0)
            return true;

        return dfs(arr, now - arr[now]) || dfs(arr, now + arr[now]);
    }
};