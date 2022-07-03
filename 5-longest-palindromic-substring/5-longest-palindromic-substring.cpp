class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        
        int start = 0, len = 1;
        for (int i = 0; i < s.size();)
        {
            if (s.size() - i <= len / 2) break;
            
            int j = i, k = i;
            
            while (k < s.size()-1 && s[k] == s[k+1]) k++;
            
            i = k + 1;
            
            while (k < s.size()-1 && j > 0 && s[k+1] == s[j-1]) k++,j--;
            
            int new_len = k - j + 1;
            if (new_len > len) {
                start = j;
                len = new_len;
            }            
        }
        
        return s.substr(start, len);
    }
};