class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> table(26);
        
        for(char i = 0; i < order.size(); i++)
            table[order[i] - 'a'] = i;
        
        return is_sorted(words.begin(), words.end(), [&](string &x, string &y){
            for(int i = 0; i < min(x.size(), y.size()); i++) {
                if(table[x[i] - 'a'] < table[y[i] - 'a'])
                    return true;
                if(table[x[i] - 'a'] > table[y[i] - 'a'])
                    return false;
            }
            
            return x.size() < y.size();
        });
    }
};