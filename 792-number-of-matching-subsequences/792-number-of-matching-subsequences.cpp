class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<string>> hash(26);
        
        for(auto &&word : words)
        {
            hash[word.back() - 'a'].push(word);
        }
        
        int cnt = 0;
        for(auto it = s.rbegin(); it != s.rend(); it++)
        {
            for(int n = hash[*it - 'a'].size(); n--;)
            {
                string temp = hash[*it - 'a'].front();
                hash[*it - 'a'].pop();
                temp.pop_back();
                if(temp.size()) hash[temp.back() - 'a'].push(temp);
                else cnt++;
            }
        }
        
        return cnt;
    }
};