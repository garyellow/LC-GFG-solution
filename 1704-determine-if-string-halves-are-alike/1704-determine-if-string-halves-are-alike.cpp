class Solution {
public:
    bool halvesAreAlike(string &s) {
        string vowels = "aeiouAEIOU";
        auto cmp = [&vowels](char &val){
            for(auto &&vowel : vowels)
                if(val == vowel) return true;
            
            return false;
        };
        
        return count_if(s.begin(), s.begin() + s.size() / 2, cmp) == count_if(s.begin() + s.size() / 2, s.end(), cmp);
    }
};