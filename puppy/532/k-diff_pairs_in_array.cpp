class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        
        map<int, int> numsMap;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            if (numsMap.find(*i) == numsMap.end()) {
                numsMap.insert(pair<int, int>(*i, 1));
            } else {
                numsMap[*i]++;
            }
        }
        
        int res(0);
        for (map<int, int>::iterator i(numsMap.begin()); i != numsMap.end(); i++) {
            if (k == 0) {
                res += ((i->second) > 1) ? 1 : 0;
            } else {
                if (numsMap.find(i->first + k) != numsMap.end()) {
                    res++;
                }
            }
        }
        return res;
    }
};
