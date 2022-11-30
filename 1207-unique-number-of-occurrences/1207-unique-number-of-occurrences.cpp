class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        unordered_set<int> times;
        
        for(auto &&num : arr)
            hash[num]++;
        
        for(auto &&[num, time] : hash)
            if(times.count(time)) return false;
            else times.insert(time);
        
        return true;
    }
};