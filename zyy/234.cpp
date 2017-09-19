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
    bool isPalindrome(ListNode *reverseHead, ListNode *&head) {
        if (reverseHead->next == NULL) {
            return head->val == reverseHead->val;
        }

        if (!isPalindrome(reverseHead->next, head)) {
            return false;
        }

        head = head->next;
        return head != NULL && reverseHead->val == head->val;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        ListNode *reverseHead(head);
        return isPalindrome(head, reverseHead);
    }
};
