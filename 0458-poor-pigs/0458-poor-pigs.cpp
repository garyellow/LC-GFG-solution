class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(floor(minutesToTest / minutesToDie) + 1));
    }
};