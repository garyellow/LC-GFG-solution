class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 ? ceil(log10(n) / log10(3)) == floor(log10(n) / log10(3)) : false;
    }
};