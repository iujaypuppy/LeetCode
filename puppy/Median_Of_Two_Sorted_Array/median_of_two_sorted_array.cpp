class Solution {
	public :
		double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
			int size_A = num1.size();
			int size_B = num2.size();
			int i = 0, j = 0;
			vector<int> merge_array;

			while (i < size_A || j < size_B) {
				if (i == size_A-1) {
					merge_array.push_back(num2[j]);
					j++;
				}
				else if (j == size_B-1) {
					merge_array.push_back(num1[i]);
					i++;
				} 
				else if (num1[i] <= num2[j]) {
					merge_array.push_back(num1[i]);
					i++;
				}
				else if (num1[i] > num2[j]){
					merge_array.push_back(num2[j]);
					j++;
				}
			}

			int size_merge = merge_array.size();
			if (size_merge % 2 != 0) {
				return merge_array[size_merge/2];
			} else {
				return (merge_array[size_merge/2] + merge_array[size_merge/2-1]) /2 ;
			}
		}
};
