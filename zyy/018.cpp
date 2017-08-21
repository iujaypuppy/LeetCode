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
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
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
                while (third > second && *third + two > target) {
                    third--;
                }

                while (third > second && *third + two == target) {
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;

        vector<int>::iterator lastFirst(nums.end());
        for (vector<int>::iterator first = nums.begin(); first != nums.end(); first++) {
            if (!skipDuplicatedElements(first, lastFirst, nums)) {
                break;
            }
            int value = *first;
            vector<int> original = nums;
            nums.erase(nums.begin(), first + 1);
            vector<vector<int>> threes = threeSum(nums, target - value);
            nums = original;
            for (vector<vector<int>>::iterator itr = threes.begin(); itr != threes.end(); itr++) {
                vector<int> four;
                four.push_back(value);
                four.insert(four.end(), itr->begin(), itr->end());
                results.push_back(four);
            }
        }

        return results;
    }
};
