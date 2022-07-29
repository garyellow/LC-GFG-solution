class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto &&word : words)
        {
            map<char, char> check;
            vector<bool> used(26);
            
            int i;
            for(i = 0; i < pattern.size(); i++)
            {
                if(check.count(pattern[i]) == 0 && used[word[i] - 'a'] == false)
                {
                    check[pattern[i]] = word[i];
                    used[word[i] - 'a'] = true;
                }
                else if(check[pattern[i]] != word[i])
                    break;
            }
            
            if(i == pattern.size())
                ans.push_back(word);
        }
        
        return ans;
    }
};