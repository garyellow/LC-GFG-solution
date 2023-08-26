class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &x, auto &y){
            return x.back() < y.back();
        });

        int cnt = 0;
        for(int i = 0, index = 0; i < pairs.size(); i++) {
            if(pairs[i].front() > pairs[index].back()) {
                index = i;
                cnt++;
            }
        }

        return cnt + 1;
    }
};