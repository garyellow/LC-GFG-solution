class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        unordered_set<int> times;
        
        for(auto &&num : arr)
            hash[num]++;
        
        for(auto &&[num, time] : hash)
            times.insert(time);
        
        return hash.size() == times.size();
    }
};