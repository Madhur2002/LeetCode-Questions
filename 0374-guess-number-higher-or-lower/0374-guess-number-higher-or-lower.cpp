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
        int high = n-1;int low = 1;
        while(low<=high){
            int m = low+(high-low)/2;
            if(guess(m) == 0){
                return m;
            }
            else if(guess(m) == -1){
                high = m-1;
            }
            else{
                low = m+1;
            }
        }
        return n;
    }
};