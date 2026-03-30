class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> s1_odd(26);
        vector<int> s2_odd(26);
        vector<int> s1_even(26);
        vector<int> s2_even(26);
        for (int i = 0; i < s1.size(); i++) {
            if (i % 2) {
                s1_even[s1[i] - 'a']++;
                s2_even[s2[i] - 'a']++;
            } else {
                s1_odd[s1[i] - 'a']++;
                s2_odd[s2[i] - 'a']++;
            }
        }

        return s1_odd == s2_odd && s1_even == s2_even;
    }
};