// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return firstBadVersion(1, n);
    }
    
    int firstBadVersion(int from, int  end) {
        if (from == end) {
            return from;
        }
        if (from + 1 == end) {
            return (isBadVersion(from) ? from : end);
        }
        
        int mid = (end - from) / 2 + from;
        if (isBadVersion(mid)) {
            return firstBadVersion(from, mid);
        } else {
            return firstBadVersion(mid, end);
        }
    }
};
