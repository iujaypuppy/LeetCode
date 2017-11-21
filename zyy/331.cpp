class Solution {
  public:
    bool getSharp(string::iterator &begin, string::iterator &end) {
        if (*begin != '#') {
            return false;
        }

        begin++;
        while (begin != end && *begin != ',') {
            begin++;
        }
        if (begin != end) {
            begin++;
        }
        return true;
    }

    bool getVal(string::iterator &begin, string::iterator &end) {
        if (!isdigit(*begin)) {
            return false;
        }
        while (begin != end && *begin != ',') {
            begin++;
        }
        if (begin != end) {
            begin++;
        }
        return true;
    }

    bool isValidSerialization(string::iterator &begin, string::iterator &end) {
        if (begin == end) {
            return false;
        }
        if (getSharp(begin, end)) {
            return true;
        }

        if (getVal(begin, end)) {
            return isValidSerialization(begin, end) &&
                    isValidSerialization(begin, end);
        }

        return false;
    }
    bool isValidSerialization(string preorder) {
        string::iterator begin(preorder.begin()), end(preorder.end());
        return isValidSerialization(begin, end) && begin == end;
    }
};
