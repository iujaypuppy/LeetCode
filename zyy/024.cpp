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
    static void getTwo(ListNode *&head, ListNode *&first, ListNode *&second) {
        first = NULL;
        second = NULL;
        if (head) {
            first = head;
            head = head->next;
        }
        if (head) {
            second = head;
            head = head->next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode *first, *second, *ret(head), *last(NULL);
        while (head) {
            getTwo(head, first, second);
            if (!second) {
                return ret;
            }

            ListNode *next(second->next);
            first->next = next;
            second->next = first;
            if (last != NULL) {
                last->next = second;
            } else {
                ret = second;
            }
            last = first;
        }
        return ret;
    }
};
