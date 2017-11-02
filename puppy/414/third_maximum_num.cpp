class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int position(-1), index(0);
        
        index = adjustSort(nums, index);
        position = (index >= 0) ? index : position;
        
        index = adjustSort(nums, index);
        
        index = adjustSort(nums, index);
        position = (index >= 0) ? index : position;
        
        return nums[position - 1];
    }
    
    /*
     * adjust array nums to keep nums[index] >= nums[index + i]
     */
    int adjustSort(vector<int>& nums, size_t index) {
        size_t len(nums.size());
        if (index >= len) {
            return -1;
        }
        
        // find biggest from index of array
        int biggest(nums[index]);
        for (size_t i(index); i < len; i++) {
            biggest = (nums[i] > biggest) ? nums[i] : biggest;
        }
        
        // adjust array
        size_t i(index), j(index);
        while (j < len) {
            if (nums[j] == biggest) {
                nums[j] = nums[i];
                nums[i] = biggest;
                i++;
            }
            j++;
        }
        return i;
    }
};
