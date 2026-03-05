class Solution {
public:
    int minOperations(string s) {
        size_t cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt += ((s[i] - '0') == (i & 1)); 
        }

        return min(cnt, s.size() - cnt);
    }
};