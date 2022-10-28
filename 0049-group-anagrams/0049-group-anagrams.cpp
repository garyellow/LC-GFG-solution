class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        unordered_map<string, vector<string>> hash;
        
        for(int i = 0; i < strs.size(); i++) {
            auto str = strs[i];
            sort(str.begin(), str.end());
            hash[str].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto &&[s, v] : hash)
            ans.push_back(v);
        
        return ans;
    }
};