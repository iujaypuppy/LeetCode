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
    class List {
      public:
        List(ListNode *h = NULL, ListNode *t = NULL):
                head(h), tail(t) {}
        ListNode *head;
        ListNode *tail;
    };
    void oddEvenList(ListNode *head, List &odd, List &even, int k) {
        if (head == NULL) {
            odd.head = odd.tail = NULL;
            even.head = even.tail = NULL;
            return;
        }

        oddEvenList(head->next, odd, even, k + 1);
        List &list(k % 2 == 0 ? even : odd);
        head->next = list.head;
        list.head = head;
        if (list.tail == NULL) {
            list.tail = head;
        }
    }

    ListNode* oddEvenList(ListNode* head) {
        List odd, even;
        oddEvenList(head, odd, even, 1);
        ListNode *ret(NULL);
        if (odd.head != NULL) {
            ret = odd.head;
            odd.tail->next = even.head;
        } else {
            ret = even.head;
        }

        return ret;
    }
};
