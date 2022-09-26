class Solution {
public:
    unordered_map<char, char> record;
    bool equationsPossible(vector<string>& equations) {
        for(char i = 'a'; i <= 'z'; i++)
            record[i] = i;
        
        sort(equations.begin(), equations.end(), [](auto &x, auto &y){
            return x[1] > y[1];
        });
        
        for(auto&& equation : equations)
        {
            if(equation[1] == '=')
                record[find(equation[0])] = find(equation[3]);
            else if(find(equation[0]) == find(equation[3]))
                return false;
        }
        
        return true;
    }
    
    char find(char val)
    {
        return record[val] == val ? val : record[val] = find(record[val]);
    }
};