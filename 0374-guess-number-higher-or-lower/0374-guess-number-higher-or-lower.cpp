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
        int low = 1;
        int high = n;
        
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int signal = guess(mid);
            if (signal == 0) {
                result = mid;
                break;
            } else if (signal == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};