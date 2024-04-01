class Solution {
public:
    int lengthOfLastWord(string s) {
        int cur = 0, ans = 0;
        
        for(auto i : s)
        {
            cur = i == ' ' ? 0 : cur + 1;
            if(cur) ans = cur;
        }
        
        return ans;
    }
};