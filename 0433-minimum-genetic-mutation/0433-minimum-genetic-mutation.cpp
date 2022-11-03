class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> record;
        for(auto &&s : bank)
            record.insert(s);
        
        queue<string> bfs({start});
        string gene = "ACGT";
        
        for(int i = 1; bfs.size(); i++) {
            for(int n = bfs.size(); n--; ) {
                auto temp = bfs.front();
                bfs.pop();
                
                for(int j = 0; j < temp.size(); j++) {
                    auto x = temp;
                    for(auto &&g : gene) {
                        if(x[j] != g) {
                            x[j] = g;
                            
                             
                            if(record.find(x) != record.end()) {
                                if(x == end) return i;
                                
                                bfs.push(x);
                                record.erase(x);
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};