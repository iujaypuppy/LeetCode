struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(null) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* res;
			int increase = 0;


			while(l1!=NULL || l2!=NULL)
			{
				int val1 = 0;
				int val2 = 0;
				int sum = 0;

				if (l1!=NULL)
				{
					val1 = l1->val;
					l1 = l1->next;
				}
				if (l2!=NULL)
				{
					val2 = l2->val;
					l2 = l2->next;
				}

				sum = val1 + val2 + increase;            
				increase = sum % 10;
				res = new ListNode(sum/10);

				res = res->next;
			}

			return res;	
		}

};
