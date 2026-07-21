class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        s = "1" + s + "1";

        int n = s.size();
        int i = 0;

        int ans = ones;

        while (i < n && s[i] == '1')
            i++;

        int cnt10 = 0;
        while (i < n && s[i] == '0') {
            cnt10++;
            i++;
        }

        while (i < n) {
            int cnt11 = 0;
            while (i < n && s[i] == '1') {
                cnt11++;
                i++;
            }

            if (cnt11 == 0)
                break;

            int cnt20 = 0;
            while (i < n && s[i] == '0') {
                cnt20++;
                i++;
            }

            if (cnt20 == 0)
                break;

            ans = max(ans, ones + cnt10 + cnt20);

            cnt10 = cnt20;
        }

        return ans;
    }
};