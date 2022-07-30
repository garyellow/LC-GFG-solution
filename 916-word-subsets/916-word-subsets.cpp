class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> hash2(26);
        for(auto &&check : words2)
        {
            vector<int> temp(26);
            
            for(auto &&c : check)
                temp[c - 'a']++;
            
            for(int i = 0; i < 26; i++)
                hash2[i] = max(hash2[i], temp[i]);
        }
        
        for(auto &&test : words1)
        {
            vector<int> hash1(26);
            for(auto &&c : test)
                hash1[c - 'a']++;
            
            int i;
            for(i = 0; i < 26; i++)
                if(hash1[i] - hash2[i] < 0)
                    break;
            
            if(i == 26) ans.push_back(test);
        }
        
        return ans;
    }
};