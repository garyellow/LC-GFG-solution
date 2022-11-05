class Solution {
public:
    unordered_set<string> pos;
    unordered_set<string> all;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &&word : words)
            for(int i = 1; i <= word.size(); i++)
                pos.insert(word.substr(0, i));
        
        string temp;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.front().size(); j++) {
                bt(temp, i, j, board);
            }
        }
        
        vector<string> ans;
        for(auto &&word : words)
            if(all.find(word) != all.end())
                ans.push_back(word);
        
        return ans;
    }
    
    void bt(string& cur, int i, int j, vector<vector<char>>& board) {
        cur.push_back(board[i][j]);
        if(pos.find(cur) == pos.end()) {
            cur.pop_back();
            return;
        }
        
        all.insert(cur);
        
        if(cur.size() < 10) {
            char c = board[i][j];
            board[i][j] = ' ';
            if(i - 1 >= 0 && board[i - 1][j] != ' ') bt(cur, i - 1, j, board);
            if(j - 1 >= 0 && board[i][j - 1] != ' ') bt(cur, i, j - 1, board);
            if(i + 1 < board.size() && board[i + 1][j] != ' ') bt(cur, i + 1, j, board);
            if(j + 1 < board.front().size() && board[i][j + 1] != ' ') bt(cur, i, j + 1, board);
            board[i][j] = c;
        }
        cur.pop_back();
    }
};