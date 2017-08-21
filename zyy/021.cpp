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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *i1, *i2, *ret(NULL), *last(NULL);
        for (i1 = l1, i2 = l2;
             i1 != NULL || i2 != NULL;
             /* empty */) {
            ListNode *current(NULL);
            if (i1 == NULL) {
                current = i2;
            } else if (i2 == NULL) {
                current = i1;
            } else {
                current = i1->val < i2->val ? i1 : i2;
            }

            if (current == i1) {
                i1 = i1->next;
            } else {
                i2 = i2->next;
            }

            current = new ListNode(current->val);

            if (ret == NULL) {
                last = ret = current;
            } else {
                last->next = current;
                last = current;
            }
        }
        return ret;
    }
};
