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
    static size_t length(ListNode *head) {
        size_t ret(0);
        while (head != NULL) {
            head = head->next;
            ret++;
        }

        return ret;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* Make sure A and B are valid */
        size_t lenA(length(headA)), lenB(length(headB));
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
