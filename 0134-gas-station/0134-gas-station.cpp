class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int all = 0, min_num = INT_MAX, min_index;
        
        for(int i = 0; i < gas.size(); i++)
        {
            all += gas[i] - cost[i];
            if(all < min_num)
            {
                min_num = all;
                min_index = i;
            }
        }
        
        if(all >= 0)
            return (min_index + 1) % gas.size();
        else 
            return -1;
    }
};