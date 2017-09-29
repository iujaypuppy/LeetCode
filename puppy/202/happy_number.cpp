class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums;
        while(n != 1) {
            if (find(nums.begin(), nums.end(), n) != nums.end()) {
                return false;
            } else {
                nums.push_back(n);
            }
            int new_n(0);
            while(n) {
                new_n += (n % 10) * (n % 10);
                n /= 10;
            }
            n = new_n;
        }
        return true;
    }
};
