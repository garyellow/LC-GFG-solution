class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto &x, auto &y){
            return x.front() != y.front() ? x.front() > y.front() : x.back() < y.back();
        });
        
        int temp = INT_MIN;
        int cnt = 0;
        
        for(auto &&ch : properties) {
            if(temp > ch.back()) cnt++;
            else temp = ch.back();
        }
        
        return cnt;
    }
};