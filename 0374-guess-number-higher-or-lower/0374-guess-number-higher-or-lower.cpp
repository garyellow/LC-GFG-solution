/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = n, mid = 1;
        
        while(l < r) {
            mid = (l + r) / 2 + 1;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1) r = mid - 1;
            else l = mid;
        }
        
        return l;
    }
};