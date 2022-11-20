class Solution {
public:
    int calculate(string s) {
        stack<int> nums; 
        int answer = 0; 
        long current_val = 0, sign = 1; 
       
        for (auto &&c : s) { 
            if (isdigit(c)) current_val = 10 * current_val + c - '0';
            else {
                switch(c) {
                    case '(':
                        nums.push(answer);    
                        nums.push(sign); 
                        answer = 0; 
                        sign = 1;
                        break;
                        
                    case ')':
                        answer += current_val * sign; 
                        current_val = 0;

                        answer = answer * nums.top();
                        nums.pop();
                        answer = answer + nums.top();
                        nums.pop();
                        break;
                        
                    case '+': case '-':
                        answer += current_val * sign; 
                        current_val = 0;
                        
                        sign = c == '+' ? 1 : -1;
                }
            }
        }
        
        answer += current_val * sign; 
        return answer; 
    }
};