class MyCalendarThree {
public:
    int maxCount = 0;
    map<int,int> mp;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int cnt = 0;
        for(auto it = mp.begin(), stop = mp.lower_bound(end); it != stop; it++) {
            maxCount = max(maxCount, cnt += it->second);
        }
        
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */