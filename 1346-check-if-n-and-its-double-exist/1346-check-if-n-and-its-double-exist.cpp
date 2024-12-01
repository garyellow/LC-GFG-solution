class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s({arr.begin(), arr.end()});
        int zero = count(arr.begin(), arr.end(), 0);
        
        return any_of(arr.begin(), arr.end(), [&zero, &s](auto& val) {
            return (val != 0 || zero >= 2) && s.count(2 * val);
        });
    }
};