class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0, cur = count(customers.begin(), customers.end(), 'Y'), mi = cur;
        for(int i = 0; i < customers.size(); i++) {
            customers[i] == 'N' ? cur++ : cur--;
            if(cur < mi) {
                ans = i + 1;
                cur = mi;
            }
        }

        return ans;
    }
};