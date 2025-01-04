class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> records(26, pair<int, int>({-1, -1}));

        for(int i = 0; i < s.size(); i++) {
            auto &[x, y] = records[s[i] - 'a'];
            if(x == -1) x = y = i;
            else y = i;
        }

        vector<int> cur(26);
        vector<vector<int>> prefix;
        for(auto &c : s) {
            cur[c - 'a']++;
            prefix.emplace_back(cur);
        }

        int ans = 0;
        for(auto &[x, y] : records) {
            if(x != -1 && x != y) {
                if(y > 0) {
                    vector<int> left = prefix[y - 1], right = prefix[x];
                    for(int i = 0; i < 26; i++) {
                        if(left[i] - right[i]) ans++;
                    }
                } 
            }
        }

        return ans;
    }
};