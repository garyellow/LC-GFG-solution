class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;

        for (char ch : to_string(n)) {
            sum += (ch - '0');
            product *= (ch - '0');
        }

        return (n % (sum + product)) == 0;
    }
};