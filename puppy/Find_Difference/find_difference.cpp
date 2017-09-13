class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> char_nums(26, 0);
		for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
			char_nums[*iter - 'a']++;
		}
		for (string::iterator iter = t.begin(); iter != t.end(); iter++) {
			char_nums[*iter - 'a']--;
		}
		char res;
		for (vector<int>::iterator iter = char_nums.begin(); iter != char_nums.end(); iter++) {
			if (*iter) {
				res = (iter - char_nums.begin()) + 'a';
				break;
			}
		}
		return res;
	}
};
