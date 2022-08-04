class Solution {
public:
    int mirrorReflection(int p, int q) {
        while((p & 1) == 0 && (q & 1) == 0){
            p >>= 1;
            q >>= 1;
        }
        
        if((p & 1) == 0 && (q & 1) != 0) return 2;
        else if((p & 1) != 0 && (q & 1) == 0) return 0;
        else return 1;
    }
};