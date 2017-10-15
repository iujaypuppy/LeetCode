class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> vals;
        for (vector<string>::iterator i(ops.begin()); i != ops.end(); i++) {
            if (*i == "C") {
                if (vals.size() > 0) {
                    vals.pop_back();
                }
            } else if (*i == "D") {
                if (vals.size() > 0) {
                    int val = vals.back() << 1;
                    vals.push_back(val);
                }
            } else if (*i == "+") {
                if (vals.size() > 1) {
                    int val = (*(vals.end() - 1)) + (*(vals.end() - 2));
                    vals.push_back(val);
                }
            } else {
                vals.push_back(stoi(*i));
            }
        }
        
        int points(0);
        for (vector<int>::iterator i(vals.begin()); i != vals.end(); i++) {
            points += *i;
        }
        return points;
    }
};
