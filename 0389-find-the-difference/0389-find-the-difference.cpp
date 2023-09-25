class Solution {
public:
    char findTheDifference(string s, string t) {
        char check = 0;
        
        for(const auto &i : t)
            check ^= i;
        
        for(const auto &i : s)
            check ^= i;
        
        return check;
    }
};