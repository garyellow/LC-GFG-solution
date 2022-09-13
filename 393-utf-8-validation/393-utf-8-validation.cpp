class Solution {
public:
    bool validUtf8(vector<int>& data) {
        reverse(data.begin(), data.end());
        
        int cur = 0, num;
        while(data.size()) {
            bitset<8> temp(data.back());
            cout << cur << ' ' << num << ' ' << temp << endl;
            
            if(cur)
            {
                if(num)
                {
                    num--;
                    if(temp[7] != 1 || temp[6] != 0)
                        return false;
                }
                
                if(num == 0)
                    cur = 0;
                
                data.pop_back();
            }
            else 
            {
                if(temp[7])
                {
                    if(temp[5] == 0)
                    {
                        cur = 1;
                        num = 1;
                    }
                    else if(temp[4] == 0)
                    {
                        cur = 1;
                        num = 2;
                    }
                    else if(temp[3] == 0)
                    {
                        cur = 1;
                        num = 3;
                    }
                    else
                        return false;
                }
                
                data.pop_back();
            }
        }
        
        return cur == 0;
    }
};