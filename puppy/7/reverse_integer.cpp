class Solution {
public:
    int reverse(int x) {
        // reverse the int for its absolute value
        string origin(to_string(abs(x)));
        std::reverse(origin.begin(), origin.end());
        
        // remove the 0s in head of reverse string value
        string withoutHeadZero("");
        for (string::iterator i(origin.begin()); i != origin.end(); i++) {
            if (*i != '0') {
                withoutHeadZero = origin.substr(i - origin.begin());
                break;
            }
        }
        
        // set value's negative and positive property
        if (x < 0) {
            withoutHeadZero = '-' + withoutHeadZero;
        }
        
        // convert sttring to int
        int res(0);
        try {
            res = stoi(withoutHeadZero);
        } catch (const std::exception &e) {
        }
        
        return res;    
    }
};
