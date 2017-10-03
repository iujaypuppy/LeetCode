/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        ListNode* pre = head;
        if (head == NULL) {
            return head;
        }
        ListNode* cur = head->next;
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};
