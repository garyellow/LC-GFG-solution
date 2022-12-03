class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for(auto &&c : s) 
            cnt[c]++;
        
        vector<pair<int, char>> record;
        for(auto &&[c, t] : cnt)
            record.push_back({t, c});
        
        sort(record.begin(), record.end(), greater<pair<int, char>>());
        
        string ans;
        for(auto &&[t, c] : record)
            while(t--)
                ans.push_back(c);
        
        return ans;
    }
};