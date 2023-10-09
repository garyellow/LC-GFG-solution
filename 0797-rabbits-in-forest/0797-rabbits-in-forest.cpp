class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnts;
        for(auto &&answer: answers) {
            cnts[answer + 1]++;
        }

        for(auto &&[num, cnt]: cnts) {
            cnt = ceil(1.0 * cnt / num) * num;
        }

        return accumulate(cnts.begin(), cnts.end(), 0, [](auto sum, auto &cur) {
            return sum + cur.second;
        });
    }
};