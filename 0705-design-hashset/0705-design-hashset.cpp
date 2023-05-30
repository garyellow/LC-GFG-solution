class MyHashSet {
public:
    MyHashSet() {
        nums = vector<int>(1e6 + 1);
    }
    
    void add(int key) {
        nums[key] = 1;
    }
    
    void remove(int key) {
        nums[key] = 0;
    }
    
    bool contains(int key) {
        return nums[key];
    }
    
    vector<int> nums;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */