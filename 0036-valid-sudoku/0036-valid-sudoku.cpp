class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<set<char>>> record = vector<vector<set<char>>>(3, vector<set<char>>(board.size()));
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.front().size(); j++) {
                if(board[i][j] == '.') continue;
                if(record[0][i].find(board[i][j]) == record[0][i].end()) record[0][i].insert(board[i][j]);
                else return false;
                if(record[1][j].find(board[i][j]) == record[1][j].end()) record[1][j].insert(board[i][j]);
                else return false;
                if(record[2][i / 3 * 3 + j / 3].find(board[i][j]) == record[2][i / 3 * 3 + j / 3].end()) record[2][i / 3 * 3 + j / 3].insert(board[i][j]);
                else return false;
            }
        }
        
        return true;
    }
};