class Solution {
  public:
    int nextIndex(vector<int> &nums, int k) {
        k++;
        if (k == nums.size()) {
            k = 0;
        }

        return k;
    }
    int nextGreaterElement(vector<int> &nums, int k) {
        for (int i(nextIndex(nums, k)); i != k; i = nextIndex(nums, i)) {
            if (nums[i] > nums[k]) {
                return i;
            }
        }
        return -1;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        /* this vector is the index of next greater element */
        vector<int> next(nums.size(), -1);
        for (int i((int)nums.size() - 1); i >= 0; i--) {
            if (i != nums.size() - 1) {
                int j(i + 1);
                bool found(false);
                while (j != -1) {
                    if (nums[j] > nums[i]) {
                        next[i] = j;
                        found = true;
                        break;
                    }
                    j = next[j];
                }

                if (found) {
                    continue;
                }
            }

            next[i] = nextGreaterElement(nums, i);
        }

        for (int i(0); i < (int)next.size(); i++) {
            if (next[i] == -1) {
                continue;
            }
            next[i] = nums[next[i]];
        }

        return next;
    }
};
