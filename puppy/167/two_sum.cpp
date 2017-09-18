class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        vector<int>::iterator i(numbers.begin());
        vector<int>::iterator j(numbers.end() - 1);
        while(i < j) {
            if (*i + *j == target) {
                res.push_back(i - numbers.begin() + 1);
                res.push_back(j - numbers.begin() + 1);
                break;
            } else if(*i + *j < target) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
