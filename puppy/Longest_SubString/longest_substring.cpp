class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int len = s.size();
			int max_len = 1;
			for (int i = 0; i<len; i++)
			{
				int res = 1;
				for (int j = i + 1; j<len; j++)
				{
					string find_str = s.substr(i, j - i);
					if (find_str.find(s[j]) != string::npos)
					{
						max_len = (res > max_len) ? res : max_len;
						break;
					}
					else
					{
						res++;
					}
				}
			}
			return max_len;	
		}
};

