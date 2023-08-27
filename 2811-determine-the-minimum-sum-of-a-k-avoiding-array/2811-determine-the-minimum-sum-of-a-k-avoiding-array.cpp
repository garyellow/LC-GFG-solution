class Solution {
public:
    int minimumSum(int n, int k) {
        long long half = k / 2 + 1;
        if(n < half) return (1 + n) * n / 2;
        else return (1 + half - 1) * (half - 1) / 2 + (k + k + n - half) * (n - half + 1) / 2;
    }
};