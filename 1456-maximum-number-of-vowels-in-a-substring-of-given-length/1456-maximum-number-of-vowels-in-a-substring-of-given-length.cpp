class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        int l = 0, r = 0;
               
        while(r < k) cnt += isVowel(s, r++);
        
        int ans = cnt;
        while(r < s.size()) {
            cnt += isVowel(s, r++);
            cnt -= isVowel(s, l++);
            
            ans = max(ans, cnt);
        }
        
        return ans;
    }
    
    inline bool isVowel(string &s, int val) {
        return (s[val] == 'a' || s[val] == 'e' || s[val] == 'i' || s[val] == 'o' || s[val] == 'u');
    }
};