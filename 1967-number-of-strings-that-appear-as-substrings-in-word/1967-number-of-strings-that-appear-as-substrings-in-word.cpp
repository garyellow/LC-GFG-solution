class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        return ranges::count_if(patterns, [&](const auto& val) {
            return word.find(val) != string::npos;
        });
    }
};