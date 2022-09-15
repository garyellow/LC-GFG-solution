class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        
        if((changed.size() & 1) == 0)
        {
            map<int, int> hash;

            for(auto &&i : changed)
                hash[i]++;
            
            for(auto &&[num, cnt] : hash)
            {
                if(cnt)
                {
                    if(hash.find(num * 2) == hash.end() || hash[num * 2] < hash[num])
                        return vector<int>();
                    else if(hash[num * 2] == 0)
                        continue;
                    
                    int n = num ? hash[num] : hash[num] / 2;
                    
                    hash[num] -= n;
                    hash[num * 2] -= n;
                    
                    while(n--)
                        ans.push_back(num);
                }
            }
        }
        
        return ans;
    }
};