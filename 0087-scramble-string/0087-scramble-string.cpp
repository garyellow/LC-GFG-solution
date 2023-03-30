class Solution {
public:
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true; 
        
        if(!dp.count(s1 + s2)) {
            vector<int> a(26), b(26), c(26);
            for(int i = 0; i < s1.size() - 1; i++) {
                a[s1[i] - 'a']++;
                b[s2[i] - 'a']++;
                c[s2[s1.size() - 1 - i] - 'a']++;

                if(a == b && isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
                    return dp[s1 + s2] = true;

                if(a == c && isScramble(s1.substr(0, i + 1), s2.substr(s1.size() - 1 - i)) && isScramble(s1.substr(i + 1), s2.substr(0, s1.size() - 1 - i)))
                    return dp[s1 + s2] = true;
            }
        }
        
        return dp[s1 + s2] = false;
    }
};