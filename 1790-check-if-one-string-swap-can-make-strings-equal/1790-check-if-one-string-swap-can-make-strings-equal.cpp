class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int dif = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (dif == -1) {
                    dif = i;
                } else if (dif >= 0) {
                    swap(s1[dif], s1[i]);
                    dif = -2;
                } else {
                    return false;
                }
            }
        }

        return s1 == s2;
    }
};