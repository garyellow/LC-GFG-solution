class Solution {
    static vector<int> primes;

public:
    Solution() {
        if (primes.empty()) {
            for (int i = 2; i <= 1000; i++) {
                int cnt = 0;
                for (int j = 1; j * j <= i; j++) {
                    if (i % j == 0) {
                        cnt++;
                    }
                }

                if (cnt == 1) {
                    primes.emplace_back(i);
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;
        for (auto& num : nums) {
            if (num <= prev) {
                return false;
            }

            auto it = lower_bound(primes.begin(), primes.end(), num - prev);
            int i = it - primes.begin() - 1;
            if (i != -1) {
                num -= primes[i];
            }
            prev = num;
        }

        return true;
    }
};

auto Solution::primes = vector<int>();