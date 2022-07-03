class Solution {
public:
    int reverse(int x) {
        string num = to_string(abs(x));
        ::reverse(num.begin(), num.end());
        try {
            return x >= 0 ? stoi(num) : -stoi(num);
        } catch(exception) {
            return 0;
        }
    }
};