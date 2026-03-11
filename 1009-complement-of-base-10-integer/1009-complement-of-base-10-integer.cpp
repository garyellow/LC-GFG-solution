class Solution {
public:
    int bitwiseComplement(int n) {
        return n ? n ^ (int)(pow(2, floor(log2(n) + 1)) - 1) : 1;
    }
};