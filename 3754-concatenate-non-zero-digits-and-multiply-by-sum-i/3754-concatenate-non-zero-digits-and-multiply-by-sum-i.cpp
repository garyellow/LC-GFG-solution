class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0)
            return 0;

        string s = to_string(n), temp;
        int sum = 0;

        for (auto c : s) {
            if (c != '0') {
                sum += (c - '0');
                temp.push_back(c);
            }
        }

        return stoll(temp) * sum;
    }
};