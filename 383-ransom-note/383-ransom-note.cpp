class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26);
        
        for(auto &&c : ransomNote)
            cnt[c - 'a']++;
        
        for(auto &&c : magazine)
            if(cnt[c - 'a']) cnt[c - 'a']--;
        
        return !(accumulate(cnt.begin(), cnt.end(), 0));
    }
};