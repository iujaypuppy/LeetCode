class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int hour(0); hour < 12; hour++) {
            int hour_leds = calbits(hour);
            if (hour_leds > num) {
                continue;
            }        
            for(int min(0); min < 60; min++) {
                int min_leds = calbits(min);
                if (min_leds == (num - hour_leds)) {
                    string time = "";
                    time += to_string(hour);
                    time += ":";
                    time += (min < 10) ? "0" : "";
                    time += to_string(min);
                    res.push_back(time);
                }
            }
        }
        return res;
    }
    
    int calbits(int num) {
        int sum(0);
        while(num) {
            sum += (num & 0x01) ? 1 : 0;
            num = num >> 1;
        }
        return sum;
    }
};
