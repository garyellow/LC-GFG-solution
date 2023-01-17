class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int l1 = 0, r0 = 0;
        
        for(auto &&c : s)
            if(c == '0') 
                r0++;
        
        int ans = r0;
        
        for(auto &&c : s) {
            if(c == '0') r0--;
            else l1++;
            
            ans = min(ans, l1 + r0);
        }
        
        return ans;
    }
};