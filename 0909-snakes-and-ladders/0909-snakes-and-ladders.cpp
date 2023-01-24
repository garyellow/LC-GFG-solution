class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<int> new_board(n * n + 1);
        for(int i = n - 1, index = 1; i >= 0; i--) {
            if((n - i) & 1) {
                for(int j = 0; j < n; j++) {
                    new_board[index++] = board[i][j];
                }
            }
            else {
                for(int j = n - 1; j >= 0; j--) {
                    new_board[index++] = board[i][j];
                }
            }
        }
        
        vector<bool> is_gone(n * n + 1);
        queue<int> bfs({1});
        is_gone[1] = true;
        
        for(int step = 1; bfs.size(); step++) {
            for(int cur = bfs.size(); cur--;) {
                int temp = bfs.front();
                bfs.pop();
                
                for(int next = temp + 1; next <= min(temp + 6, n * n); next++) {
                    if(!is_gone[next]) {
                        is_gone[next] = true;
                        
                        if(max(next, new_board[next]) == n * n) return step;
                        
                        bfs.push(new_board[next] == -1 ? next : new_board[next]);
                    }
                }
            }
        }
        
        return -1;
    }
};