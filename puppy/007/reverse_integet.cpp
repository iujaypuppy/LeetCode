class Solution {
	public:
		int reverse(int x) {
			if(x>=1000000000)
				return 0;
			int reverse_int = 0;
			int origin_int = x;
			x = abs(x);
			while (x != 0) {
				reserver_int = reverse_int * 10 + (x % 10);
				x = x/10;
			}
			return (origin_int >= 0) ? reverse_int : (0-reverse_int);
		}
}
