class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<long> s, sums(arr.size(),0);
        long j, res = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            while (s.size() && arr[s.back()] > arr[i])
                s.pop_back();
            
            j = s.size() ? s.back() : -1;
            
            sums[i] = ((j >= 0 ? sums[j] : 0) + (i - j) * arr[i]) % int(1e9 + 7);
            s.push_back(i);
        }

        for(auto &&num : sums)
            res = (res + num) % int(1e9 + 7);
        
        return res;
    }
};