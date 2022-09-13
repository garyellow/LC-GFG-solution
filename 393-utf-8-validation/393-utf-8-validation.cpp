class Solution {
public:
    bool validUtf8(vector<int>& data) {
        reverse(data.begin(), data.end());
        
        bool cur = false;
        int num;
        
        while(data.size()) {
            bitset<8> temp(data.back());
            
            if(cur)
            {
                if(num--)
                    if(temp[7] != 1 || temp[6] != 0)
                        return false;
                
                if(num == 0)
                    cur = false;
            }
            else if(temp[7])
            {
                cur = true;
                if(temp[5] == 0) num = 1;
                else if(temp[4] == 0) num = 2;
                else if(temp[3] == 0) num = 3;
                else return false;
            }
            
            data.pop_back();
        }
        
        return cur == 0;
    }
};