class Solution {
public:
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> arr;
        vector<int> cnt(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], i});
        
        mergeSort(0, arr.size() - 1, arr, cnt);
        
        return cnt;
    }
    
    void mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int> &cnt)
    {
        if(left >= right)
            return;
        
        int mid = left + (right - left) / 2;
        
        mergeSort(left, mid, arr, cnt);
        auto a = vector<pair<int, int>>({arr.begin() + left, arr.begin() + mid + 1});
        mergeSort(mid + 1, right, arr, cnt);
        auto b = vector<pair<int, int>>({arr.begin() + mid + 1, arr.begin() + right + 1});
        
        int num = mid + 1;
        merge(a.begin(), a.end(), b.begin(), b.end(), arr.begin() + left, [&cnt,&num,right](auto &l, auto &r){
            if(l.first >= r.first)
            {
                num++;
                return true;
            }
            else
            {
                cnt[r.second] += right - num + 1;
                return false;
            }
        });
    }
};