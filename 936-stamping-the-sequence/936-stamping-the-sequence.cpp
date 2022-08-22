class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        bool change = true;
        
        int cnt;
        for(cnt = 0; change && cnt < 10 * target.size(); cnt++)
        {
            change = false;
            for(int i = 0; i + stamp.size() <= target.size(); i++)
            {
                string temp = target.substr(i, stamp.size());
                if(check(stamp, temp))
                {
                    ans.push_back(i);
                    for(int k = i; k < i + stamp.size(); k++)
                    {
                        if(target[k] != ' ')
                        {
                            change = true;
                            target[k] = ' ';
                        }
                    }
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return target == string(target.size(), ' ') && cnt < 10 * target.size() ? ans : vector<int>();
    }
    
    bool check(const string &x, const string &y)
    {
        for(int i = 0; i < x.size(); i++)
            if(x[i] != ' ' && y[i] != ' ' && x[i] != y[i])
                return false;
        
        return true;
    }
};