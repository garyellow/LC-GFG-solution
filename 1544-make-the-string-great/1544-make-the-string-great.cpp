class Solution {
public:
    string makeGood(string s) {
        for(int i = 1; s.size() > 1 && i < s.size();) {
            if(abs(s[i] - s[i - 1]) == 32) {
                s.erase(s.begin() + i - 1);
                s.erase(s.begin() + i - 1);
                i = max(i - 1, 1);
            }
            else
                i++;
        }
        
        return s;
    }
};