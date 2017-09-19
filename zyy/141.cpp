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
    ListNode *next(ListNode *node) {
        if (node == NULL) {
            return NULL;
        }

        return node->next;
    }
    bool hasCycle(ListNode *head) {
        ListNode *oneStep(head), *twoSteps(head);
        do {
            oneStep = next(oneStep);
            twoSteps = next(next(twoSteps));
        } while (oneStep != twoSteps);

        return oneStep != NULL;
    }
};
