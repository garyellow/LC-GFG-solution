class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3);
        for (auto i : stones)
            cnt[i % 3]++;

        if (min(cnt[1], cnt[2]) == 0)
            return max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 > 0;
        else
            return abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
    }
};