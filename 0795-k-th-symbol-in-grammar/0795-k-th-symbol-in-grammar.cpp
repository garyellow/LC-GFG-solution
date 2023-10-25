class Solution {
public:
    int kthGrammar(int n, int k) {
        return bitset<32>(k - 1).count() & 1;
    }
};