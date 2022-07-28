class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26);
        
        for(auto &&c : s)
            cnt[c-'a']++;
        
        for(auto &&c : t)
            cnt[c-'a']--;
        
        for(auto &&c : cnt)
            if(c != 0) return false;
        
        return true;
    }
};