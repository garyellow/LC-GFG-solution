class Solution {
public:
    string makeFancyString(string s) {
        string str;

        char last = 0;
        int cnt = 0;
        for(auto &&ch : s) {
            if(ch == last) {
                cnt++;
            }
            else {
                cnt = 1;
                last = ch;
            }
            if(cnt >= 3) {
                continue;
            }

            str.push_back(ch);
        }

        return str;
    }
};