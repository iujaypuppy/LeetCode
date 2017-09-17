class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int R = (int)(sqrt(double(area)));
        while(R >= 1) {
            if (!(area % R)) {
                res.push_back(area / R);
                res.push_back(R);
                break;
            }
            R--;
        }
        return res;
    }
};
