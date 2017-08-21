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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* count length of list */
        int length(0);
        for (ListNode *node = head; node != NULL; node = node->next) {
            length++;
        }

        /* position from beginning */
        n = length + 1 - n;
        if (n <= 0) {
            return head;
        }

        ListNode *last(NULL), *node(head);
        for (int i = 1; i < n; i++) {
            last = node;
            node = node->next;
        }

        if (last) {
            last->next = node->next;
        } else {
            node = node->next;
            head = node;
        }

        return head;
    }
};
