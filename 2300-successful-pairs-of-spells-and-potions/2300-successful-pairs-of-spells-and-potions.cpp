class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        vector<int> ans;
        
        for(auto &&spell : spells) {
            double cur = 1.0 * success / spell;
            
            int loc = potions.end() - lower_bound(potions.begin(), potions.end(), cur);
            ans.push_back(loc);
        }
        
        return ans;
    }
};