class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        multiset<string> record;
        
        for(auto &&word : words)
            record.insert(word);
        
        int len = words.front().size();
        
        vector<int> ans;
        for(int start = 0; start < len; start++)
        {
            int l = start, r = start + len * (words.size() - 1);
            
            multiset<string> cur;
            for(int i = l; i <= r; i += len)
                cur.insert(s.substr(i, len));
            
            if(cur == record) ans.push_back(l);
            
            for(r += len; r + len <= s.size(); l += len, r += len)
            {
                cur.erase(cur.find(s.substr(l, len)));
                cur.insert(s.substr(r, len));
                
                if(cur == record) ans.push_back(l + len);
            }
        }
        
        return ans;
    }
};