class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.front().size(); j++) {
                if(board[i][j] == word.front() && find(i, j, 0, board, word)) return true;
            }
        }
        
        return false;
    }
    
    bool find(int i, int j, int cur, vector<vector<char>>& board, string& word) {
        if(cur == word.size() - 1) return true;
        char c = board[i][j];
        board[i][j] = '.';
        
        if(i - 1 >= 0 && board[i - 1][j] == word[cur + 1] && find(i - 1, j, cur + 1, board, word)) return true;
        if(j - 1 >= 0 && board[i][j - 1] == word[cur + 1] && find(i, j - 1, cur + 1, board, word)) return true;
        if(i + 1 < board.size() && board[i + 1][j] == word[cur + 1] && find(i + 1, j, cur + 1, board, word)) return true;
        if(j + 1 < board.front().size() && board[i][j + 1] == word[cur + 1] && find(i, j + 1, cur + 1, board, word)) return true;
        
        board[i][j] = c;
        return false;
    }
};