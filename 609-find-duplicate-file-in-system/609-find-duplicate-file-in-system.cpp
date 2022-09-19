class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> record;
        
        for(auto &&path : paths)
        {
            string forder;
            
            for(auto &&ch : path)
            {
                if(ch == ' ') break;
                forder += ch;
            }
            
            path = path.substr(forder.size() + 1, path.size() - forder.size());
            
            auto file = spilt(path);
            
            for(auto &&[name, content] : file)
                record[content].push_back(forder + '/' + name);
        }
        
        vector<vector<string>> ans;
        
        for(auto &&[content, path] : record)
        {
            if(path.size() <= 1) continue;
            
            vector<string> temp;
            
            for(auto &&each : path)
                temp.push_back(each);
            
            ans.push_back(temp);
        }
            
        
        return ans;
    }
    
    vector<pair<string, string>> spilt(string &files)
    {
        vector<pair<string, string>> all;
        string file;
        string file_name;
        string file_content;
            
        for(auto &&ch : files)
        {
            if(ch == ' ')
            {
                for(auto &&c : file)
                {
                    if(c == '(')
                    {
                        file_content = file.substr(file_name.size() + 1, file.size() - file_name.size() - 2);
                        break;
                    }
                    
                    file_name += c;
                }
                
                all.push_back({file_name, file_content});
                file.clear();
                file_name.clear();
                file_content.clear();
                continue;
            }
            
            file += ch;
        }
        
        for(auto &&c : file)
        {
            if(c == '(')
            {
                file_content = file.substr(file_name.size() + 1, file.size() - file_name.size() - 2);
                break;
            }

            file_name += c;
        }

        all.push_back({file_name, file_content});
        
        return all;
    }
};