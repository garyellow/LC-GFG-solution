class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        for (auto& c : s) {
            result.push_back(c);
            if (result.size() >= part.size() &&
                result.substr(result.size() - part.size()) == part) {
                result.erase(result.size() - part.size());
            }
        }
        return result;
    }
};