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
    void getKNodes(ListNode *&head, int k, vector<ListNode*> &results) {
        results.clear();
        for (int i = 0; i < k; i++) {
            if (!head) {
                return;
            }

            results.push_back(head);
            head = head->next;
        }
    }
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *ret(head), *last(NULL);
        while (head) {
            vector<ListNode*> nodes;
            getKNodes(head, k, nodes);
            if (nodes.size() < k) {
                return ret;
            }

            /* reverse process */
            ListNode *next = (*(nodes.end() - 1))->next;
            for (vector<ListNode*>::iterator i = nodes.begin(); i != nodes.end(); i++) {
                if (i == nodes.begin()) {
                    (*i)->next = next;
                    continue;
                }

                (*i)->next = *(i - 1);
            }
            if (last) {
                last->next = *(nodes.end() - 1);
            } else {
                ret = *(nodes.end() - 1);
            }
            last = *nodes.begin();
        }
        return ret;
    }
};
