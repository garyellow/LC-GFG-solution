class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> str(26);
        vector<int> pat(26);
        vector<int> anagrams;

        if(s.size() < p.size()) return anagrams;

        for(auto &&ch : p)
            pat[ch - 'a']++;

        for (int i = 0; i < p.size(); i++)
            str[s[i] - 'a']++;

        if(pat == str) anagrams.push_back(0);
        for (int L = 0, R = p.size(); R < s.size(); L++, R++)
        {
            str[s[L] - 'a']--;
            str[s[R] - 'a']++;

            if(pat == str) anagrams.push_back(L + 1);
        }

        return anagrams;
    }
};