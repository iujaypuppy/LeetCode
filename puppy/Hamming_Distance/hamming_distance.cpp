class HammingInt
{
public:
    int hammingInt;
    
    HammingInt(int x) {
        hammingInt = x;
    }
    
    int calculate_distance(HammingInt* other) {
        vector<int> a = this->calculate_bits(this->hammingInt);
        vector<int> b = other->calculate_bits(other->hammingInt);
        int size_a = a.size();
        int size_b = b.size();
        
        int i = 0, res = 0;
        while(i < size_a || i < size_b) {
            if (i < size_a && i < size_b && a[i] != b[i]) {
                res++;
            } else if (i < size_a && i >= size_b && a[i] != 0) {
                res++;
            } else if (i >= size_a && i < size_b && b[i] != 0) {
                res++;
            }
            i++;    
        }     
        return res;
    }
    
    vector<int> calculate_bits(int x) {
        vector<int> bits;
        while(x != 0) {
            bits.push_back(x % 2);
            x = x /2;
        }
        return bits;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        HammingInt hamming_x(x);
        HammingInt hamming_y(y);
        int hamming_distance = hamming_x.calculate_distance(&hamming_y);
        
        return hamming_distance;
    }
};


