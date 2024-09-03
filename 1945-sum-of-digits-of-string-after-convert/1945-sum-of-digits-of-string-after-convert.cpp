class Solution {
public:
    int getLucky(string s, int k) {
        string number;
        for (auto&& c : s) {
            number += to_string(c - 'a' + 1);
        }

        while (k > 0) {
            int temp = 0;
            for (auto&& c : number) {
                temp += c - '0';
            }
            number = to_string(temp);
            k--;
        }
        return stoi(number);
    }
};