class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        
        while(l < r) {
            while(l < r && !is_vowel(s[l])) l++;
            while(l < r && !is_vowel(s[r])) r--;
            
            swap(s[l++], s[r--]);
        }
        
        return s;
    }
    
    bool is_vowel(char c) {
        c = tolower(c);
        string check = "aeiou";
        
        for(auto &&ch : check)
            if(ch == c)
                return true;
        
        return false;
    }
};