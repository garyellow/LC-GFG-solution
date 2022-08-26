class Solution {
public:
    static set<vector<int>> all_ans;
    Solution() {
        if(all_ans.empty())
        {
            for(long i = 1; i <= INT_MAX; i *= 2)
            {
                vector<int> temp(10);
                int cur = i;

                while(cur)
                {
                    temp[cur % 10]++;
                    cur /= 10;
                }

                all_ans.insert(temp);
            }
        }
    }
    bool reorderedPowerOf2(int n) {
        vector<int> temp(10);
        int cur = n;

        while(cur)
        {
            temp[cur % 10]++;
            cur /= 10;
        }
        
        return all_ans.find(temp) != all_ans.end();
    }
};

set<vector<int>> Solution::all_ans;