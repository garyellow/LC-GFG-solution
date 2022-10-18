class Solution {
public:
    static vector<string> record;
    
    Solution () {
        if(record.empty()) {
            int n = 29;
            string cur = "1";
            record.push_back(cur);
            
            while(n--) {
                string temp = cur;
                cur.clear();
                
                char last = '\0';
                int cnt = 0;
                for(auto &&num : temp) {
                    if(last != '\0' && last != num) {
                        cur += to_string(cnt) + last;
                        cnt = 0;
                    }
                    
                    last = num;
                    cnt++;
                }
                
                cur += to_string(cnt) + last;
                
                record.push_back(cur);
            }
        }
    }
    
    string countAndSay(int n) {
        return record[n - 1];
    }
};

vector<string> Solution::record;