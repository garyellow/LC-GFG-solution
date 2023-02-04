class Solution
{
public:
    bool checkInclusion(string& s1, string& s2)
    {
        if (s1.size() > s2.size())
            return false;

        vector<int> cnt1(26);
        vector<int> cnt2(26);

        for (auto &&i : s1)
            cnt1[i - 'a']++;

        for (int i = 0; i < s1.size(); i++)
            cnt2[s2[i] - 'a']++;

        if (cnt1 == cnt2)
            return true;

        for (int i = s1.size(); i < s2.size(); i++)
        {
            cnt2[s2[i - s1.size()] - 'a']--;
            cnt2[s2[i] - 'a']++;

            if (cnt1 == cnt2)
                return true;
        }

        return false;
    }
};