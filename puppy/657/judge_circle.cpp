class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int length = moves.size();
        for (int i=0; i<length; i++) {
            switch (moves[i] ) {
                case 'R' :
                    x++;
                    break;
                case 'L' :
                    x--;
                    break;
                case 'U' :
                    y++;
                    break;
                case 'D' :
                    y--;
                    break;
            }
        }
        
        return (x==0) && (y==0);
    }
};
