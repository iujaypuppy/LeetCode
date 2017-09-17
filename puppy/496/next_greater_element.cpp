class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int finds_n = findNums.size();
        int nums_n = nums.size();
        vector<int> res;
        for (int i = 0; i < finds_n; i++) {                          
            bool start_search = false;
            bool is_find_greater = false;
            for (int j = 0; j < nums_n; j++) {
                if (start_search) {
                    if (findNums[i] < nums[j]) {
                        res.push_back(nums[j]);
                        is_find_greater = true;
                        break;
                    }
                }
                if (findNums[i] == nums[j]) {
                    start_search = true;
                }
            }
            if (!is_find_greater) {                     
                res.push_back(-1);
            }
        }
        return res;
    }
};
