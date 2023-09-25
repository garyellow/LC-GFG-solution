class Solution {
public:
    char findTheDifference(string s, string t) {
        char check = 0;
        
        for(auto &&i : t)
            check ^= i;
        
        for(auto &&i : s)
            check ^= i;
        
        return check;
    }
};