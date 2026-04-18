class Solution {
public:
    int mirrorDistance(int n) {
        string tmp = to_string(n);
        ranges::reverse(tmp);

        return abs(stoi(tmp) - n);
    }
};