class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        
        set<string> s;

        for(auto &&word : words) {
            string temp;

            for(auto &&ch : word)
                temp += m[ch - 'a'];
            
            s.insert(temp);
        }
        
        return s.size();
    }
};