class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> hash;
        
        for(auto &&task : tasks) 
            hash[task]++;
        
        int cnt = 0;
        for(auto &&[num, time] : hash) {
            if(time == 1) return -1;
            else cnt += time / 3 + (bool)(time % 3);
        }
        
        return cnt;
    }
};