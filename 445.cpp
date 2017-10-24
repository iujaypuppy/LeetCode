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
    int length(ListNode *node) {
        if (node == NULL) {
            return 0;
        }

        return length(node->next) + 1;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int gap, int &carry) {
        if (l1 == NULL || l2 == NULL) {
            carry = 0;
            return NULL;
        }

        ListNode *ret(addTwoNumbers(l1->next, gap > 0 ? l2 : l2->next,
                                    gap > 0 ? gap - 1 : gap, carry));
        static const int BASE(10);
        int sum(l1->val + (gap > 0 ? 0 : l2->val) + carry);
        ListNode *tmp(new ListNode(sum % BASE));
        tmp->next = ret;
        ret = tmp;
        carry = sum / BASE;

        return ret;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1(length(l1)), length2(length(l2)), gap(abs(length1 - length2));
        if (length1 < length2) {
            ListNode *tmp(l1);
            l1 = l2;
            l2 = tmp;
        }
        int carry;
        ListNode *ret(addTwoNumbers(l1, l2, gap, carry));
        if (carry > 0) {
            ListNode *tmp(new ListNode(carry));
            tmp->next = ret;
            ret = tmp;
        }

        return ret;
    }
};
