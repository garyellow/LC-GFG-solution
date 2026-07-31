class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);

        for (auto w : word) {
            cnt[w - 'a']++;
        }

        int ans = 0;
        priority_queue<int> pq(cnt.begin(), cnt.end());
        for (int num = 0; !pq.empty() && pq.top(); pq.pop(), num++) {
            ans += pq.top() * (num / 8 + 1);
        }

        return ans;
    }
};