/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
    ListNode* mid;
    
    int listLen;
    bool isPalindrome;
    
    void calTailListNode() {
        ListNode* tmp = head;
        if (tmp == NULL) {
            return;
        }
        
        listLen = 1;
        while (tmp->next != NULL) {
            tmp = tmp->next;
            listLen++;
        }
        tail = tmp;
    }
    
    void calMidListNode() {
        ListNode* tmp = head;
        if (tmp == NULL) {
            return;
        }
        
        int i(0), midCount(listLen / 2);
        while (i < midCount) {
            tmp = tmp->next;
            i++;
        }
        mid = tmp;
    }
    
    void reverseFromMidListNode() {
        ListNode* pre = mid;
        if (pre == NULL) {
            return;
        }
        ListNode* next = pre->next;
        if (next == NULL) {
            return;
        }
        while (pre != NULL && next != NULL) {
            ListNode* tmp = next->next;
            next->next = pre;
            pre = next;
            next = tmp;
        }
    }
    
    void compare() {
        ListNode* i = head;
        ListNode* j = tail;
        
        int count(0), midCount(listLen / 2);
        while (count < midCount) {
            if (i->val != j->val) {
                isPalindrome = false;
                return;
            }
            i = i->next;
            j = j->next;
            count++;
        }
        isPalindrome = true;;
    }
public:
    LinkedList(ListNode* a) : head(a) {
        listLen = 0;
        isPalindrome = false;
    }
    
    // Eg, 5->4->3->4->5
    // step1: get head, mid, tail. (5(head)->4->3(mid)->4->5(tail))
    // step2: reverse from mid.    (5(head)->4->3(mid)<-4<-5(tail))
    // step3: compare
    bool isPalindromeList() {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        calTailListNode();
        calMidListNode();
        
        reverseFromMidListNode();
        
        compare();
        
        return isPalindrome;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        LinkedList list(head);
        return list.isPalindromeList();
    }
};
