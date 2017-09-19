class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            int rank = 1;
            for (vector<int>::iterator j(nums.begin()); j != nums.end(); j++) {
                if (*j > *i) {
                    rank++;
                }
            }
            switch (rank) {
                case 1 :
                    res.push_back("Gold Medal");
                    break;
                case 2 :
                    res.push_back("Silver Medal");
                    break;
                case 3 :
                    res.push_back("Bronze Medal");
                    break;
                default :
                    res.push_back(to_string(rank));
                    break;
                    
            }
        }
        return res;
    }
};
