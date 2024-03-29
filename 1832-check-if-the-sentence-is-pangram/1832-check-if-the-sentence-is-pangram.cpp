class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> ch;
        
        for(auto &&c : sentence)
            ch.insert(c);
        
        return ch.size() == 26;
    }
};