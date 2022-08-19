class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> cnt;
        
        for(auto &&num : nums)
            cnt[num]++;
        
        while(cnt.size())
        {
            int last = cnt.begin()->first;
            int temp = cnt.begin()->second;
            
            int len = 0;
            for(auto it = cnt.begin(); it != cnt.end(); it++)
            {
                if(it->first - last <= 1 && it->second - temp >= 0)
                {
                    last = it->first;
                    temp = it->second;
                    
                    if(--(it->second) == 0)
                        cnt.erase(it);
                }
                else break;
                
                len++;
            }

            if(len < 3) return false;
        }
        
        return true;
    }
};