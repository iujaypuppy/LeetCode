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
    class ListNodeWrapper {
      public:
        ListNodeWrapper(ListNode *n): node(n) {}
        ListNode *node;
        inline bool operator<(const ListNodeWrapper& other) const {
            if (node == NULL) {
                return true;
            }
            if (other.node == NULL) {
                return false;
            }

            return node->val > other.node->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        vector<ListNodeWrapper> vec;
        for (vector<ListNode*>::iterator i = lists.begin(); i != lists.end(); i++) {
            vec.push_back(ListNodeWrapper(*i));
        }
        make_heap(vec.begin(), vec.end());
        ListNode *head(NULL), *last(NULL);
        while (vec.front().node != NULL) {
            ListNode *now = vec.front().node;
            if (last) {
                last->next = now;
                last = now;
            } else {
                head = last = now;
            }
            pop_heap(vec.begin(), vec.end());
            vec.pop_back();

            now = now->next;
            vec.push_back(ListNodeWrapper(now));
            push_heap(vec.begin(), vec.end());
        }

        return head;
    }
};
