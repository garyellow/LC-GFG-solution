class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> record;
        int ans = 0;
        int l = 0, r = 0;
        
        while(r < s.size())
        {
            if(record[s[r]]) record[s[l++]] = false;
            else record[s[r++]] = true;
            
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};