class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = count(moves.begin(), moves.end(), 'L');
        int R = count(moves.begin(), moves.end(), 'R');
        
        return moves.size() - 2 * min(L, R);
    }
};