class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26);
        
        for(auto &&c : s)
            cnt[c - 'a']++;
        
        set<char> nonrepeat;
        
        for(int i = 0; i < cnt.size(); i++)
            if(cnt[i] == 1) nonrepeat.insert(i + 'a');
        
        if(nonrepeat.empty()) return -1;
        else
        {
            for(int i = 0; i < s.size(); i++)
                if(nonrepeat.find(s[i]) != nonrepeat.end())
                    return i;
        }
        
        return -1;
    }
};