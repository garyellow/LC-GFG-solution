class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; i++)
            bt(i, i, n, k);
        
        return ans;
    }
    
    void bt(int sum, int last_num, const int &n, const int &k)
    {
        if(int(log10(sum)) + 1 == n)
        {
            ans.push_back(sum);
            return;
        }
        
        if(k != 0)
        {
            if(last_num - k >= 0) bt(sum * 10 + last_num - k, last_num - k, n, k);
            if(last_num + k <= 9) bt(sum * 10 + last_num + k, last_num + k, n, k);
        }
        else 
            bt(sum * 10 + last_num, last_num, n, k);
    }
};