class Solution {
public:
    unordered_map<string, string> u;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double> record;
        for(auto &&i : equations)
        {
            u[i.front()] = i.front();
            u[i.back()] = i.back();
        }
        
        for(size_t i = 0; i < equations.size(); i++)
        {
            if(record.count(equations[i].front()) + record.count(equations[i].back()) == 0)
            {
                record[equations[i].front()] = values[i];
                record[equations[i].back()] = 1;
            }
            else if(record.count(equations[i].front()) + record.count(equations[i].back()) == 2)
            {
                double ratio = record[equations[i].front()] / values[i] / record[equations[i].back()];
                for(auto &&r : record)
                    if(find(r.first) == find(equations[i].back()))
                        r.second *= ratio;
            }
            else if(record.count(equations[i].front()))
                record[equations[i].back()] = record[equations[i].front()] / values[i];
            else
                record[equations[i].front()] = record[equations[i].back()] * values[i];
            
            u[find(equations[i].front())] = find(equations[i].back());
        }
        
        vector<double> ans;
        for(auto &&i : queries)
        {
            if(record.count(i.front()) && record.count(i.back()) && find(i.front()) == find(i.back()))
                ans.push_back(record[i.front()] / record[i.back()]);
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
    
    string find(string val)
    {
        return u[val] == val ? val : u[val] = find(u[val]);
    }
};