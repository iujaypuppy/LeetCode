class Solution {
  public:
    bool judgeCircle(string moves) {
        int rightSteps(0), downSteps(0);
        for (string::iterator i(moves.begin()); i != moves.end(); i++) {
            switch(*i) {
                case 'U':
                    downSteps--;
                    break;
                case 'D':
                    downSteps++;
                    break;
                case 'L':
                    rightSteps--;
                    break;
                case 'R':
                    rightSteps++;
                    break;
                default:
                    break;
            }
        }

        return rightSteps == 0 && downSteps == 0;
    }
};
