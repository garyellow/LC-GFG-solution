class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int index = 0;
        
        for(auto &ch : str1) {
            if(index == str2.size()) break;
            
            if(str2[index] == ch || str2[index] == ((ch - 'a' + 1) % 26) + 'a') index++;
        }
        
        return index == str2.size();
    }
};