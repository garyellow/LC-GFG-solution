class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> record;

        for(auto &&row : mat) {
            record.push_back(accumulate(row.begin(), row.end(), 0));
        }

        vector<int> index(record.size());
        iota(index.begin(), index.end(), 0);
        stable_sort(index.begin(), index.end(), [&](auto &i, auto &j) {
            return record[i] < record[j];
        });
           
        return {index.begin(), index.begin() + k};
    }
};