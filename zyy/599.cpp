class Solution {
  public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        vector<string> &less = list1.size() < list2.size() ? list1 : list2;
        vector<string> &more = list1.size() >= list2.size() ? list1 : list2;
        for (size_t i(0); i <= less.size() + more.size() - 2 && result.empty(); i++) {
            for (size_t i1(0); i1 <= i && i1 < less.size(); i1++) {
                size_t i2 = i - i1;
                if (i2 >= more.size()) {
                    continue;
                }
                if (less[i1] == more[i2]) {
                    result.push_back(less[i1]);
                }
            }
        }
        return result;
    }
};
