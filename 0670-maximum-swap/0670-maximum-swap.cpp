class Solution {
public:
    int maximumSwap(int num) {
        
        string str = to_string(num);
        int i = 0;
        for(int i = 0; i < str.size(); i++) {
            auto it = max_element(str.begin() + i, str.end(), less_equal<int>());

            if(*it != *(str.begin() + i)) {
                iter_swap(it, str.begin() + i);
                break;
            }
        }

        return stoi(str);
    }
};