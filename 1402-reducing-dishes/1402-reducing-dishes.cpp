class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int temp = 0;
        for_each(satisfaction.begin(), satisfaction.end(), [&](int &val){val = temp += val;});
        
        int sum = 0, r = satisfaction.size() - 1, l = satisfaction.size() - 2;
        for(; l >= -1 && satisfaction[r] - (l == -1 ? 0 : satisfaction[l]) > 0; l--)
            sum += satisfaction[r] - (l == -1 ? 0 : satisfaction[l]);
        
        return sum;
    }
};