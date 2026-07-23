class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        long n = nums.size(), m = nums.size();

        m |= m >> 1;
        m |= m >> 2;
        m |= m >> 4;
        m |= m >> 8;
        m |= m >> 16;

        return (m + 1) >> (3 / (n + 1));
    }
};