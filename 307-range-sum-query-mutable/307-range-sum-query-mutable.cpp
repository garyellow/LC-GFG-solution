class NumArray {
public:
    vector<int> st;
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        st.resize(4 * nums.size());
        this->nums = nums;
        
        build(1, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        update(index, val, 1, 0, nums.size() - 1);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 1, 0, nums.size() - 1);
    }
    
    void build(int x, int l, int r){
        if (l == r){
            st[x] = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(x << 1, l, mid);
        build((x << 1) | 1, mid+1, r);
        pull(x);
    }
    
    void pull(int x){
        st[x] = st[x << 1] + st[(x << 1) | 1];
    }
    
    int query(int ql, int qr, int x, int l, int r){
        if (ql <= l && qr >= r){
            return st[x];
        }
        int ret = 0;
        int mid = (l + r) >> 1;
        if (ql <= mid){
            ret += query(ql, qr, x << 1, l, mid);
        }
        if (qr > mid){
            ret += query(ql, qr, (x << 1) | 1, mid + 1, r);
        }
        return ret;
    }
    
    void update(int pos, int val, int x, int l, int r){
        if (l == r){
            st[x] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(pos, val, x << 1, l, mid);
        else update(pos, val, (x << 1) | 1, mid + 1, r);
        pull(x);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */