class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty())
            return {};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < arr.size(); ++i) {
            heap.push({arr[i], i});
        }

        int cnt = 1, last;
        vector<int> ans(arr.size());
        do {
            last = heap.top().first;
            while (heap.size() && heap.top().first == last) {
                auto [_, index] = heap.top();
                heap.pop();
                ans[index] = cnt;
            }

            cnt++;
        } while (heap.size());

        return ans;
    }
};