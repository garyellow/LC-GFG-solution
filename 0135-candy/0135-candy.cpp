class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size());
        vector<int> index(ratings.size());
        iota(index.begin(), index.end(), 0);

        stable_sort(index.begin(), index.end(), [&](auto &i, auto &j) {
            return ratings[i] < ratings[j];
        });

        for(auto &&i : index) {
            candy[i] = max(i == 0 || ratings[i - 1] == ratings[i] ? 0 : candy[i - 1], i == ratings.size() - 1 || ratings[i + 1] == ratings[i] ? 0 : candy[i + 1]) + 1;
        }

        return accumulate(candy.begin(), candy.end(), 0);
    }
};