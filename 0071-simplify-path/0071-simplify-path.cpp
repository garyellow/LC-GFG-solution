class Solution
{
public:
    string simplifyPath(string path)
    {
        char *cut = new char[path.size() + 1];
        strcpy(cut, path.c_str());
        path.clear();

        vector<string> record;
        for (cut = strtok(cut, "/"); cut != nullptr; cut = strtok(nullptr, "/"))
        {
            if (strcmp(cut, "..") == 0)
            {
                if (record.size())
                    record.pop_back();
            }
            else if (strcmp(cut, ".") != 0)
                record.push_back(cut);
        }

        for (auto &&i : record)
            path += '/' + i;

        return path.empty() ? "/" : path;
    }
};