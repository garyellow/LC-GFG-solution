class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return count(derived.begin(), derived.end(), 1) % 2 == 0;
    }
};