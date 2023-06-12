class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        int last = nums.front(), lastest = nums.front();
        for (auto &&i : vector<int>(nums.begin() + 1, nums.end()))
        {
            if (i == last + 1)
            {
                last = i;
            }
            else
            {
                if (last == lastest)
                {
                    ans.push_back(to_string(lastest));
                }
                else
                {
                    ans.push_back(to_string(lastest) + "->" + to_string(last));
                }
                lastest = last = i;
            }
        }

        if (last == lastest)
        {
            ans.push_back(to_string(lastest));
        }
        else
        {
            ans.push_back(to_string(lastest) + "->" + to_string(last));
        }

        return ans;
    }
};