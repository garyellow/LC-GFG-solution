class Solution {
public:
    int myAtoi(string s) {
        bool start = false;
        bool positive = true;
        long num = 0;
        
        for(const auto &i : s)
        {
            if(start)
            {
                if(isdigit(i))
                {
                    num *= 10;
                    num += i - '0';
                    
                    if(positive && num > INT_MAX)
                    {
                        num = INT_MAX;
                        break;
                    }
                    else if(!positive && num > -(long)INT_MIN)
                    {
                        num = -(long)INT_MIN;
                        break;
                    }
                }
                else
                    break;   
            }
            else
            {
                if(i == '-' || i == '+')
                {
                    positive = i == '+';
                    start = true;
                }
                else if(isdigit(i))
                {
                    num = i - '0';
                    start = true;
                }
                else if(i != ' ')
                    break;
            }
        }
        
        return positive ? num : -num;
    }
};