class Solution {
public:
    long long minimumPossibleSum(long long n, long long target) {
        long long half = target / 2 + 1;
        if(n < half) return (1 + n) * n / 2;
        else return (1 + half - 1) * (half - 1) / 2 + (target + target + n - half) * (n - half + 1) / 2;
    }
};