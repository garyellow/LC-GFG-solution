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
    
    vector<pair<int, int>> mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int> &cnt)
    {
        if(left >= right)
            return {arr.begin() + left, arr.begin() + right + 1};
        
        int mid = left + (right - left) / 2;
        
        auto a = mergeSort(left, mid, arr, cnt);
        auto b = mergeSort(mid + 1, right, arr, cnt);
        
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
        
        return {arr.begin() + left, arr.begin() + right + 1};
    }
};