class Solution {
public:
    Solution() {
        if (save.empty())
            for (int e = 2, num = 0; e <= 9; e++) {
                num = next_num(e);
                save.push_back(num);
                while (num % 10 != 9) {
                    num = next_num(num, e);
                    save.push_back(num);
                }
            }
    }

    vector<int> sequentialDigits(int low, int high) {
        return vector<int>(ranges::lower_bound(save, low),
                           ranges::upper_bound(save, high, less<int>()));
    }

    int next_num(int e) {
        int num = 0;
        for (int n = 1; n <= e; n++) {
            num *= 10;
            num += n;
        }
        return num;
    }

    int next_num(int num, int e) {
        int plus = 0;
        for (int n = 1; n <= e; n++) {
            plus *= 10;
            plus += 1;
        }
        return num + plus;
    }

    static vector<int> save;
};

vector<int> Solution::save;