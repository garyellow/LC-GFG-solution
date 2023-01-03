class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete_count = 0;
        
        for(int j = 0; j < strs.front().size(); j++)
        {
            for(int i = 0; i < strs.size() - 1; i++)
            {
                if(strs[i][j] > strs[i + 1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};