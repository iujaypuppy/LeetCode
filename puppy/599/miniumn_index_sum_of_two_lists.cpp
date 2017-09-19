class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> resturant_indexs;
        for (vector<string>::iterator i(list1.begin()); i != list1.end(); i++) {
            resturant_indexs.insert(pair<string, int>(*i, list1.begin() - i));
        }
        int min_indexs = list1.size() + list2.size() - 2;
        for (vector<string>::iterator i(list2.begin()); i != list2.end(); i++) {
            if (resturant_indexs.find(*i) != resturant_indexs.end()) {
                resturant_indexs[*i] = (i - list2.begin()) + abs(resturant_indexs[*i]);
                min_indexs = min(min_indexs, resturant_indexs[*i]);
            }
        }
        vector<string> res;
        for (map<string, int>::iterator i(resturant_indexs.begin()); i != resturant_indexs.end(); i++) {
            if (i->second == min_indexs) {
                res.push_back(i->first);
            }
        }
        return res;
    }
};
