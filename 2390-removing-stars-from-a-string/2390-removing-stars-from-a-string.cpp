class Solution {
public:
    string removeStars(string s) {
        string str;
        
        for(auto &&c : s) {
            if(c == '*') {
                if(str.size()) str.pop_back();
            }
            else {
                str.push_back(c);
            }
        }
        
        return str;
    }
};