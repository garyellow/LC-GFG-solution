class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int len = 0;
        vector<string> temp;
        for(auto &&word : words) {
            if(len + temp.size() + word.size() > maxWidth) {
                if(temp.size() == 1) {
                    ans.push_back(temp.front() + string(maxWidth - len, ' '));
                }
                else {
                    int space = (maxWidth - len) / (temp.size() - 1);
                    int extra = (maxWidth - len) % (temp.size() - 1);

                    string cur = temp.front();

                    for(int i = 1; i < temp.size(); i++) {
                        cur += string(space + (extra-- > 0), ' ');
                        cur += temp[i];
                    }

                    ans.push_back(cur);
                }

                len = 0;
                temp.clear();
            }

            len += word.size();
            temp.push_back(word);
        }

        string cur = temp.front();
        for(int i = 1; i < temp.size(); i++) {
            cur += ' ' + temp[i];
        }
        ans.push_back(cur + string(maxWidth - cur.size(), ' '));

        return ans;
    }
};