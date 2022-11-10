class Solution {
public:
    string removeDuplicates(string s) {
        string str;
        for(auto &&c : s) {
            if(str.size() && str.back() == c) str.pop_back();
            else str.push_back(c);
        }
        
        return str;
    }
};