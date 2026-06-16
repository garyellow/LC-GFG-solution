class Solution {
public:
    string processStr(string s) {
        string res;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '*') {
                if (res.length() != 0) {
                    res.pop_back();
                }
            } else if (ch == '#') {
                res += res;
            } else if (ch == '%') {
                ranges::reverse(res);
            } else if (islower(ch)) {
                res.push_back(ch);
            }
        }

        return res;
    }
};