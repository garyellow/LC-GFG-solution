class Solution {
public:
    bool check(double target, vector<int>& quantities, int n) {
        auto cnt = accumulate(quantities.begin(), quantities.end(), 0,
                              [&target](auto&& sum, auto& val) {
                                  return sum + int(ceil(val / target));
                              });

        return cnt <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());

        while (l < r) {
            auto mid = (l + r) / 2;
            if (check(mid, quantities, n)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};