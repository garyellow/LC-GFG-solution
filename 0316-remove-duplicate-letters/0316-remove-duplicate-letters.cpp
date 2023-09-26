class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> cnt(26);
        vector<bool> filled(26);

        for (auto &&i : s)
            cnt[i - 'a']++;

        string now;
        for (auto &&i : s) {
            cnt[i - 'a']--;

            if (!filled[i - 'a']) {
                while (!now.empty() && now.back() > i && cnt[now.back() - 'a'] > 0) {
                    filled[now.back() - 'a'] = false;
                    now.pop_back();
                }

                filled[i - 'a'] = true;
                now.push_back(i);
            }
        }

        return now;
    }
};