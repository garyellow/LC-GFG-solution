class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, result = 0;
        vector<int> cnt(3, 0);

        while(r < s.size()) {
            cnt[s[r++]  - 'a']++;

            while(ranges::count(cnt, 0) == 0) {
                result += (s.size() - r + 1);
                cnt[s[l++]  - 'a']--;
            }
        }

        return result;
    }
};