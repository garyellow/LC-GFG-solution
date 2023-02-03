class Solution {
public:
    string convert(string& s, int numRows) {
        if(numRows == 1) return s;
        vector<string> datas(numRows);
        
        int index = 0;
        bool zigzag = true; 
        for(auto &&ch : s) {
            if(zigzag) datas[index++].push_back(ch);
            else datas[index--].push_back(ch);
            
            if(index == 0 || index == numRows - 1) zigzag = !zigzag;
        }
        
        return accumulate(datas.begin(), datas.end(), string());
    }
}; 