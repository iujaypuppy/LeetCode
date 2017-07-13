/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* head of return list */
        ListNode *ret = NULL;
        /* tail of return list: highest digit */
        ListNode *highest = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int one = (l1 == NULL) ? 0 : l1->val;
            int another = (l2 == NULL) ? 0 : l2->val;
            int result = (one + another + carry) % 10;
            carry = (one + another + carry) / 10;
            ListNode *node = new ListNode(result);
            if (highest) {
                highest->next = node;
                highest = node;
            } else {
                ret = highest = node;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return ret;
    }
};
