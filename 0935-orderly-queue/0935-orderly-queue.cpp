class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k >= 2) {
            sort(s.begin(), s.end());
            return s;
        }
        
        string ans = s;
        for(int i = 1; i < s.size(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            ans = min(ans, s);
        }

        return ans;
    }
};