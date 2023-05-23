class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): K(k) {
        sort(nums.begin(),nums.end(),greater<int>());
        
        for(auto &&i : nums)
            if(arr.size() < k)
                arr.push(i);
    }
    
    int add(int val) {
        if(arr.size() < K)
            arr.push(val);
        else if(val > arr.top()) {
            arr.pop();
            arr.push(val);
        }
        
        return arr.top();
    }
    
    int K;
    priority_queue<int, vector<int>, greater<int>> arr;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */