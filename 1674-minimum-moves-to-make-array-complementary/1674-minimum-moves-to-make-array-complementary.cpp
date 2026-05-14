class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> delta(limit * 2 + 2);

        for (int i = 0; i < nums.size() / 2; i++) {
            int mi = nums[i];
            int ma = nums[nums.size() - 1 - i];
            if (mi > ma)
                swap(mi, ma);

            delta[2] += 2;
            delta[mi + 1]--;
            delta[mi + ma]--;
            delta[mi + ma + 1]++;
            delta[ma + limit + 1]++;
        }

        int res = nums.size(), moves = 0;
        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};