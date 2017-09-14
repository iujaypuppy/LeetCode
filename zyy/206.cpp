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
    /* Solution switch: iterative or recursive */
    static const bool ITERATIVE = true;
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        if (ITERATIVE) {
            ListNode *last(NULL), *next;
            while (head != NULL) {
                next = head->next;
                head->next = last;
                last = head;
                head = next;
            }

            return last;
        } else {
            ListNode *next(head->next);
            if (next == NULL) {
                return head;
            }

            ListNode *newHead(reverseList(next));
            next->next = head;
            head->next = NULL;
            return newHead;
        }

        return NULL;
    }
};
