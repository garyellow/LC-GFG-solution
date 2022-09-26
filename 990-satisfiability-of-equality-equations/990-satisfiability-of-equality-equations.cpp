class Solution {
public:
    map<char, char> record;
    bool equationsPossible(vector<string>& equations) {
        vector<bool> check(26);
        for(char i = 'a'; i <= 'z'; i++)
            record[i] = i;
        
        sort(equations.begin(), equations.end(), [](auto &x, auto &y){
            return x[1] > y[1];
        });
        
        for(auto&& equation : equations)
        {
            if(equation[1] == '=')
            {
                record[find(equation[0])] = find(equation[3]);
                check[equation[0] - 'a'] = check[equation[3] - 'a'] = true;
            }
            else
            {
                if(equation[0] == equation[3] || check[equation[0] - 'a'] && check[equation[3] - 'a'])
                {
                    if(find(equation[0]) == find(equation[3]))
                        return false;
                }
            }
        }
        
        return true;
    }
    
    char find(char val)
    {
        return record[val] == val ? val : record[val] = find(record[val]);
    }
};