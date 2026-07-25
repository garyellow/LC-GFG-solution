class Solution {
public:
    int maxProduct(int n) {
        uint64_t m = 0;
        for (; n; n /= 10)
            m += 1ULL << (n % 10 << 2);

        int u = (bit_width(m) - 1) >> 2;
        return u * ((bit_width(m - (1ULL << (u << 2))) - 1) >> 2);
    }
};