class Solution {
private:
    static constexpr string happies = "abc";
    string backtrack(int& m, string& cur, int n, int k) {
        if (cur.size() == n) {
            m++;

            return m == k ? cur : "";
        }

        for (const auto& happy : happies) {
            if (cur.empty() || cur.back() != happy) {
                cur.push_back(happy);

                auto temp = backtrack(m, cur, n, k);
                if (!temp.empty()) {
                    return temp;
                }

                cur.pop_back();
            }
        }

        return "";
    }

public:
    string getHappyString(int n, int k) {
        int m = 0;
        string cur;

        return backtrack(m, cur, n, k);
    }
};