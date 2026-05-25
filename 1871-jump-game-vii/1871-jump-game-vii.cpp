class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1')
            return false;

        for (auto it = s.begin() + 1; it != s.begin() + minJump; it++) {
            *it = '1';
        }

        if (*min_element(s.begin() + minJump, s.begin() + maxJump) == '1') {
            for (auto it = s.begin() + maxJump + 1;
                 it != min(s.begin() + maxJump + minJump, s.end()); it++) {
                *it = '1';
            }
        }

        for (auto it = s.rbegin() + 1; it != s.rbegin() + minJump; it++) {
            *it = '1';
        }
        if (*min_element(s.rbegin() + minJump, s.rbegin() + maxJump) == '1') {
            for (auto it = s.rbegin() + maxJump + 1;
                 it != min(s.rbegin() + maxJump + minJump, s.rend()); it++) {
                *it = '1';
            }
        }

        int now = 0, max_step = INT_MIN;
        for (auto i : s)
            if (i - '0') {
                max_step = max(max_step, ++now);
            } else {
                now = 0;
            }

        return max_step < maxJump;
    }
};