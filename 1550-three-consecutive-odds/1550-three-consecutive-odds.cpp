class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int last = 0, i = 0; i < arr.size(); ++i) {
            if (arr[i] & 1)
                ++last;
            else
                last = 0;

            if (last == 3)
                return true;
        }

        return false;
    }
};