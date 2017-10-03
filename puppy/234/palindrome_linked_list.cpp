/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while(head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }
        size_t len = vals.size();
        for (size_t i(0); i < len / 2; i++) {
            if (vals[i] != vals[len - i - 1 ]) {
                return false;
            }
        }
        return true;
    }
};
