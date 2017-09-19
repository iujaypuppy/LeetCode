/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> vals;
        ListNode* node = head;
        while (node != NULL) {
            vals.push_back(node->val);
            node = node->next;
        }
        node = head;
        int i = vals.size() - 1;
        while (node != NULL) {
            node->val = vals[i];
            i--;
            node = node->next;
        }
        return head;
    }
};
