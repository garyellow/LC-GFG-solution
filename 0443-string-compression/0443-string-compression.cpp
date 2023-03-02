class Solution {
public:
    int compress(vector<char>& chars) {
        string temp;
        int cur = 0, last = -1;
        
        for(auto &&ch : chars) {
            if(ch == last) {
                cur++;
            }
            else {
                if(last != -1) temp.push_back(last);
                if(cur > 1) temp += to_string(cur);
                last = ch;
                cur = 1;
            }
        }
        
        temp.push_back(last);
        if(cur > 1) temp += to_string(cur);
        
        chars = vector<char>(temp.begin(), temp.end());
        
        return chars.size();
    }
};