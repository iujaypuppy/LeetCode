class Solution {
  public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator left(height.begin()), right(height.end() - 1);
        int max = 0;
        while (left < right) {
            int area = (right - left) * (*left < *right ? *left : *right);
            max = area > max ? area : max;

            /* move the cursor with less height and try to increase the area */
            if (*left < *right) {
                vector<int>::iterator itr = left + 1;
                while (itr < right && *itr <= *left) {
                    itr++;
                }

                left = itr;
            } else {
                vector<int>::iterator itr = right - 1;
                while (itr > left && *itr <= *right) {
                    itr--;
                }

                right = itr;
            }
        }
        return max;
    }
};
