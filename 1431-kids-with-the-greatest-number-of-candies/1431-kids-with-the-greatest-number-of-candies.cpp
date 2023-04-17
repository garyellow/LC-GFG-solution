class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int g = *max_element(candies.begin(), candies.end());
        
        vector<bool> ans;
        for(auto &&candy : candies) 
            ans.push_back(candy + extraCandies >= g);
        
        return ans;
    }
};