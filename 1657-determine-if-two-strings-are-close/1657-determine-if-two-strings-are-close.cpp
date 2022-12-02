class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> hash1, hash2;
        unordered_map<int, int> times1, times2;
        unordered_set<int> char1, char2;
        
        for(auto &&c : word1)
            hash1[c]++;
        
        for(auto &&c : word2)
            hash2[c]++;
        
        for(auto &&[c, time] : hash1) {
            char1.insert(c);
            times1[time]++;
        }
        
        for(auto &&[c, time] : hash2) {
            char2.insert(c);
            times2[time]++;
        }
        
        return char1 == char2 && times1 == times2;
    }
};