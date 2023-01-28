class SummaryRanges {
public:
    set<vector<int>> data;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto cur = upper_bound(data.begin(), data.end(), vector({value, value}));
        
        if(cur == data.end()) {
            if(cur == data.begin() || value - (--cur)->at(1) > 1) {
                data.insert({value, value});
            }
            else if(value - cur->at(1) == 1) {
                int temp = cur->at(0);
                data.erase(cur);
                data.insert({temp, value});
            }
        }
        else if(cur == data.begin()) {
            if(cur->at(0) - value > 1) {
                data.insert({value, value});
            }
            else if(cur->at(0) - value == 1) {
                int temp = cur->at(1);
                data.erase(cur);
                data.insert({value, temp});
            }
        }
        else {
            int before = (--cur)->at(1), now = (++cur)->at(0);
            if(before < value && now > value) {
                if(now - before == 2) {
                    int temp = (--cur)->at(0);
                    int temp2 = (++cur)->at(1);
                    data.erase(cur--);
                    data.erase(cur);
                    data.insert({temp, temp2});
                }
                else if(value - before == 1) {
                    int temp = (--cur)->at(0);
                    data.erase(cur);
                    data.insert({temp, value});
                }
                else if(now - value == 1) {
                    int temp = cur->at(1);
                    data.erase(cur);
                    data.insert({value, temp});
                }
                else {
                    data.insert({value, value});
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(data.begin(), data.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */