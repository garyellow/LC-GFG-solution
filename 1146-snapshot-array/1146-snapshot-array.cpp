class SnapshotArray {
public:
    vector<vector<pair<int, int>>> s;
    int cur;
    SnapshotArray(int length) {
        s = vector<vector<pair<int, int>>>(length, {{0, 0}});
        cur = 0;
    }
    
    void set(int index, int val) {
        s[index].push_back({cur, val});
    }
    
    int snap() {
        return cur++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(s[index].begin(), s[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */