class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> num;
        
        long num1, num2;
        for(auto &&token : tokens) {
            if(token == "+") {
                num1 = num.top(), num.pop();
                num2 = num.top(), num.pop();
                num.push(num2 + num1);
            }
            else if(token == "-") {
                num1 = num.top(), num.pop();
                num2 = num.top(), num.pop();
                num.push(num2 - num1);
            }
            else if(token == "*") {
                num1 = num.top(), num.pop();
                num2 = num.top(), num.pop();
                num.push(num2 * num1);
            }
            else if(token == "/") {
                num1 = num.top(), num.pop();
                num2 = num.top(), num.pop();
                num.push(num2 / num1);
            }
            else {
                num.push(stoi(token));
            }
        }
        
        return num.top();
    }
};