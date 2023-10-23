class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 ? ceil(log2(n) / log2(4)) == floor(log2(n) / log2(4)) : false;
    }
};