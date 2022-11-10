class Solution {
public:
    string makeGood(string s) {
        string str;
        for(auto &&c : s) {
            if(str.size() && abs(str.back() - c) == 32) str.pop_back();
            else str.push_back(c);
        }
        
        return str;
    }
};