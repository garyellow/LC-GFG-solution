class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int now = 1, cnt;
        vector<bool> check(k, false);

        for (now = 1, cnt = 1; now < k; now = now * 10 + 1, cnt++)
            ;

        for (now %= k; now; cnt++) {
            if (check[now])
                return -1;
            else
                check[now] = true;

            now = now * 10 + 1;
            now %= k;
        }

        return cnt;
    }
};