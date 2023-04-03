class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int cnt = 0;
        for(int l = 0, r = people.size() - 1; l <= r; r--, cnt++)
            if(people[l] + people[r] <= limit) l++;
        
        return cnt;
    }
};