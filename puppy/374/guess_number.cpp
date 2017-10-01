int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return guess_number(1, n);
    }
    
    int guess_number(int from, int to) {
        if(from + 1 == to) {
            if (guess(from) == 0) {
                return from;
            } else {
                return to;
            }
        }
        
        int mid = from + (to - from) / 2;
        int answer = guess(mid);
        if (answer == -1) {
            return guess_number(from, mid);
        } else if (answer == 1) {
            return guess_number(mid, to);
        } else {
            return mid;
        }
    }
};
