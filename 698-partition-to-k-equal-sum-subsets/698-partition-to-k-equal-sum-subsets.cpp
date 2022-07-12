class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        map<int, int> cnt;
        int sum = 0;
        
        for(auto &&s : nums)
        {
            cnt[s]++;
            sum += s;
        }
        
        if(sum % k != 0 || cnt.rbegin()->first > sum / k) return false;
        
        return trytry(cnt, cnt.rbegin(), sum, k, sum / k, 0);
    }
    
    bool trytry(map<int, int> &cnt, map<int, int>::reverse_iterator last, const int all, const int k, const int num, int cur)
    {
        for(auto it = last; it != cnt.rend(); it++)
        {
            if(it->second)
            {
                it->second--;
                cur += it->first;
                if(cur == all)
                    return true;
                else if(cur == num && trytry(cnt, cnt.rbegin(), all, k, num + all / k, cur))
                    return true;
                else if(cur < num && trytry(cnt, it, all, k, num, cur))
                    return true;
                cur -= it->first;
                it->second++;
            }
        }
        
        return false;
    }
};