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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        int i = 0;
        while (i < n) {
            ++i;
            p2 = p2->next;
        }
        if (p2 == NULL) return head->next;
        p2 = p2->next;
        while (p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* temp = p1->next;
        p1->next = p1->next->next;
        delete temp;
        return head;
    }
};
