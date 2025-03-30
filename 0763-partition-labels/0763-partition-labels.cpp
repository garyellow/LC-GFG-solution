class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> interval(26, {-1, -1});
        for (int i = 0; i < s.size(); i++)
            if (interval[s[i] - 'a'].first < 0)
                interval[s[i] - 'a'].first = i;

        for (int i = s.size() - 1; i >= 0; i--)
            if (interval[s[i] - 'a'].second < 0)
                interval[s[i] - 'a'].second = i;

        map<int, int> hash;
        for (auto&& i : interval)
            if (i.first >= 0)
                hash[i.first] = i.second;

        vector<int> ans;
        int small = hash.begin()->first;
        int big = hash.begin()->second;
        for (auto i = hash.begin(); i != hash.end(); i++) {
            if (i->first <= big)
                big = max(big, i->second);
            else {
                ans.push_back(big - small + 1);
                small = i->first;
                big = i->second;
            }
        }

        ans.push_back(big - small + 1);

        return ans;
    }
};