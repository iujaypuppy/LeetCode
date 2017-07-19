class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int len = s.size();
			if (len == 0) return 0;

			int max_len = 1;
			for (int i = 0; i<len; i++)
			{
				int res = 1;
				for (int j = i + 1; j<len; j++)
				{
					string find_str = s.substr(i, j - i);
					if (find_str.find(s[j]) != string::npos)
					{
						break;
					}
					else
					{
						res++;
					}
				}
				max_len = (res > max_len) ? res : max_len;
			}
			return max_len;	
		}
};

