class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int j = colors.size();
        int left = 0, right = 0;

        for (int i = 0; i < j; i++)
            if (colors[i] ^ colors[j - 1]) {
                left = j - 1 - i;
                break;
            }

        for (int i = 0; i < j; i++)
            if (colors[j - 1 - i] ^ colors[0]) {
                right = j - 1 - i;
                break;
            }

        return max(left, right);
    }
};