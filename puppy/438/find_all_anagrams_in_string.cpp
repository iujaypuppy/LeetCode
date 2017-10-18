class Solution {
public:
	void adjustFlagByIndex(vector<int> sAlphts, vector<int> pAlphts, int index, int & sFlag) {
		if ((sAlphts[index] == pAlphts[index])
			|| (sAlphts[index] > pAlphts[index] && pAlphts[index] > 0)) {
			sFlag |= (1 << index);
		}
		else {
			sFlag &= ~(1 << index);
		}
	}

	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		size_t lenS(s.size()), lenP(p.size());
		if (lenS < lenP) {
			return res;
		}

		const static int alphtSize = 26;
		vector<int> pAlphts(alphtSize, 0);
		vector<int> sAlphts(alphtSize, 0);
		for (size_t i(0); i < lenP; i++) {
			pAlphts[p[i] - 'a']++;
			sAlphts[s[i] - 'a']++;
		}

		int pFlag = 0x3ffffff;
		int sFlag = 0x3ffffff;
		for (size_t i(0); i < alphtSize; i++) {
			size_t index = i;
			adjustFlagByIndex(sAlphts, pAlphts, index, sFlag);
		}
		if (sFlag == pFlag) {
			res.push_back(0);
		}

		for (size_t i(0); i < (lenS - lenP); i++) {
			size_t index = s[i] - 'a';
			sAlphts[index]--;
			adjustFlagByIndex(sAlphts, pAlphts, index, sFlag);

			index = s[i + lenP] - 'a';
			sAlphts[index]++;
			adjustFlagByIndex(sAlphts, pAlphts, index, sFlag);

			if (sFlag == pFlag) {
				res.push_back(i + 1);
			}
		}

		return res;
	}
};
