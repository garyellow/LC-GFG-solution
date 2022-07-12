class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        map<int, int> cnt;
        int sum = 0;
        
        for(auto &&s : matchsticks)
        {
            cnt[s]++;
            sum += s;
        }
        
        if(sum % 4 != 0) return false;
        
        return trytry(cnt, cnt.rbegin(), sum, sum / 4, 0);
    }
    
    bool trytry(map<int, int> &cnt, map<int, int>::reverse_iterator last, const int all, const int num, int cur)
    {
        for(auto it = last; it != cnt.rend(); it++)
        {
            if(it->second)
            {
                it->second--;
                cur += it->first;
                if(cur == all && num == all)
                    return true;
                else if(cur == num && trytry(cnt, cnt.rbegin(), all, num + all / 4, cur))
                    return true;
                else if(cur < num && trytry(cnt, it, all, num, cur))
                    return true;
                cur -= it->first;
                it->second++;
            }
        }
        
        return false;
    }
};