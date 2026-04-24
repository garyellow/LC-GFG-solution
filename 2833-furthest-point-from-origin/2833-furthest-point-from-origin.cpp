class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = ranges::count(moves, 'L');
        int R = ranges::count(moves, 'R');

        return moves.size() - 2 * min(L, R);
    }
};