class MyCalendar {
public:
    map<int, int> records;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &&record : records)
            if(record.first < end && record.second > start)
                return false;
        
        records.insert({start, end});
        return true;
    }
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */