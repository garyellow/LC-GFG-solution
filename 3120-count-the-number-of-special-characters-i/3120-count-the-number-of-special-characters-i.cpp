class Solution {
public:
    static int numberOfSpecialChars(string& word) {
        bitset<26> l, u;
        for (auto c : word) {
            if (c >= 'a')
                l[c - 'a'] = 1;
            else
                u[c - 'A'] = 1;
        }

        return (l & u).count();
    }
};