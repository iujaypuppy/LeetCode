class Solution {
  public:
    bool skipDuplicatedElements(vector<int>::iterator &itr,
                                vector<int>::iterator &last,
                                vector<int> &vec) {
        if (last == vec.end()) {
            last = itr;
            return true;
        }
        while (itr != vec.end() && *itr == *last) {
            itr++;
        }

        if (itr == vec.end()) {
            return false;
        }

        last = itr;
        return true;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;

        vector<int>::iterator lastFirst(nums.end());
        for (vector<int>::iterator first = nums.begin(); first != nums.end(); first++) {
            /* skip duplicated elements */
            if (!skipDuplicatedElements(first, lastFirst, nums)) {
                break;
            }
            vector<int>::iterator lastSecond(nums.end());
            vector<int>::iterator third(nums.end() - 1);
            for (vector<int>::iterator second = first + 1; second != nums.end(); second++) {
                if (!skipDuplicatedElements(second, lastSecond, nums)) {
                    break;
                }

                int two = *first + *second;
                vector<int>::iterator lastThird(nums.end());
                while (third > second && *third + two > 0) {
                    third--;
                }

                while (third > second && *third + two == 0) {
                    if (lastThird == nums.end() || *lastThird != *third) {
                        vector<int> zero;
                        zero.push_back(*first);
                        zero.push_back(*second);
                        zero.push_back(*third);
                        ret.push_back(zero);
                        lastThird = third;
                    }
                    third--;
                }

                if (third == second) {
                    break;
                }
            }
        }

        return ret;
    }
};
