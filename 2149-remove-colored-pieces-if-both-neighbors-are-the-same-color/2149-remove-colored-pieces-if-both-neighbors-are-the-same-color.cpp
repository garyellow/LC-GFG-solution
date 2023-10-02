class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for(int i = 1; i < colors.size() - 1; i++) {
            if(colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                a += colors[i] == 'A';
                b += colors[i] == 'B';
            }
        }

        return a > b;
    }
};