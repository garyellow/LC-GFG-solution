class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> record;
        
        for(auto &&match : matches) {
            record[match.front()];
            record[match.back()]++;
        }
        
        vector<int> zero, one;
        for(auto &&[num, loss] : record) {
            if(loss == 0) zero.push_back(num);
            if(loss == 1) one.push_back(num);
        }
        
        return {zero, one};
    }
};