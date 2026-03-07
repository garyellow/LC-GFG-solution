class Solution {
public:
    int minFlips(string s) {
        int odd0 = 0, odd1 = 0, even0 = 0, even1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i & 1) {
                if (s[i] == '0') {
                    odd0++;
                } else {
                    odd1++;
                }
            } else {
                if (s[i] == '0') {
                    even0++;
                } else {
                    even1++;
                }
            }
        }

        int result = numeric_limits<int>::max();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                even0--;

                swap(odd0, even0);
                swap(odd1, even1);

                if (s.size() & 1) {
                    even0++;
                } else {
                    odd0++;
                }

            } else {
                even1--;

                swap(odd1, even1);
                swap(odd0, even0);

                if (s.size() & 1) {
                    even1++;
                } else {
                    odd1++;
                }
            }

            result = min(result, min(odd1 + even0, odd0 + even1));
        }

        return result;
    }
};