class MyHashMap {
public:
    MyHashMap() {
        nums = vector<int>(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        nums[key] = value; 
    }
    
    int get(int key) {
        return nums[key];
    }
    
    void remove(int key) {
        nums[key] = -1;
    }
    
    vector<int> nums;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */