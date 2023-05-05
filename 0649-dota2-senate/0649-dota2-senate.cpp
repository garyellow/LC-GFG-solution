class Solution {
public:
    string predictPartyVictory(string senate) {
        int skip = 0;
        
        queue<char> s;
        
        for(auto &&p : senate)
            s.push(p);
        
        while(abs(skip) < senate.size()) {
            auto i = s.front();
            s.pop();
            
            if(skip == 0) {
                if(i == 'R') skip++;
                else skip--;
                
                s.push(i);
            }
            else if(skip > 0) {
                if(i == 'R') {
                    skip++;
                    s.push(i);
                }
                else skip--;
            }
            else {
                if(i == 'R')
                    skip++;
                else {
                    skip--;
                    s.push(i);
                }
            }
        }
        
        return skip > 0 ? "Radiant" : "Dire";
    }
};