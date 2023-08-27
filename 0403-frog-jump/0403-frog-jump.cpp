class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<bool>> isGone(stones.size(), vector<bool>(stones.size()));
        
        return helper(0, 0, stones, isGone);
    }

    bool helper(int index, int step, vector<int>& stones, vector<vector<bool>> &isGone) {
        if(index == stones.size() - 1) return true;

        if(!isGone[index][step]) {
            isGone[index][step] = true;
            for(int s = max(step - 1, 1); s <= step + 1; s++) {
                auto it = lower_bound(stones.begin(), stones.end(), stones[index] + s);
                if(it != stones.end() && *it == stones[index] + s) {
                    if(helper(it - stones.begin(), s, stones, isGone)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};