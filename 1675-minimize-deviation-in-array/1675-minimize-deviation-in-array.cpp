class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        vector<int> backup = nums;
        for (auto &&i : backup)
            while ((i & 1) == 0)
                i /= 2;

        priority_queue<int> max_v;
        max_v.push(*max_element(backup.begin(), backup.end()));

        vector<pair<int, int>> p_nums;
        for (auto &&i : nums)
            p_nums.push_back({i, i});

        for (auto &&i : p_nums)
            while ((i.first & 1) == 0 && i.first > max_v.top())
                i.first /= 2;

        priority_queue<int, vector<int>, greater<int>> min_v;
        for (auto &&i : p_nums)
            min_v.push(i.first);

        sort(p_nums.begin(), p_nums.end());

        int check = max_v.top() - p_nums[0].first;
        for (int i = 0; i < nums.size() && (p_nums[i].first & 1 || p_nums[i].first * 2 <= p_nums[i].second); i++)
        {
            if (min_v.top() == p_nums[i].first)
                min_v.pop();

            max_v.push(p_nums[i].first * 2);
            min_v.push(p_nums[i].first * 2);

            check = min(check, max_v.top() - min_v.top());
        }
        
        return check;
    }
};