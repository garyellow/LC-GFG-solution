class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> record;
        
        int ans = 0;
        for(int l = 0, r = 0; r < fruits.size();) {
            if(record.size() <= 2) {
                record[fruits[r++]]++;
            }
            
            while(record.size() > 2) {
                record[fruits[l++]]--;
                if(record[fruits[l - 1]] == 0) record.erase(fruits[l - 1]);
            }
            
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};