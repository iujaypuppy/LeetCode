#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> tmp(nums);
		vector<int> twoVals;

		sort(tmp.begin(), tmp.end());
		twoVals = twoSumInSortVector(tmp, target);

		return findPosition(nums, twoVals[0], twoVals[1]);
	}
	vector<int> twoSumInSortVector(vector<int>& nums, int target)
	{
		int start = 0;
		int end = nums.size()-1;
		vector<int> res;

		while (start < end)
		{
			if (nums[start] + nums[end] < target)
			{
				start++;
			}
			else if (nums[start] + nums[end] > target)
			{
				end--;
			}
			else
			{
				res.push_back(nums[start]);
				res.push_back(nums[end]);
				break;
			}
		}

		return res;
	}

	vector<int> findPosition(vector<int>& nums, int val1, int val2)
	{
		int pos[] = { -1, -1 };
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == val1 && pos[0] < 0)
			{
				pos[0] = i;
				continue;
			}
			if (nums[i] == val2 && pos[1] < 0)
			{
				pos[1] = i;
			}
		}
	    vector<int> res(pos, pos+2);
		return res;
	}
};
