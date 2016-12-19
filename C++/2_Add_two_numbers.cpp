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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *res = NULL;
        ListNode *tt;
        ListNode *ll1 = l1, *ll2 = l2;
        int c = 0;
        while (ll1 != NULL && ll2 != NULL) {
            int v = ll1->val + ll2->val + c;
            if (v >= 10) {
                c = 1;
                v = v - 10;
            }
            else {
                c = 0;
            }
            if (res == NULL) {
                res = new ListNode(v);
                tt = res;
            }
            else {
                tt->next = new ListNode(v);
                tt = tt->next;
            }
            ll1 = ll1->next;
            ll2 = ll2->next;
        }
        ListNode *llt = (ll1 == NULL) ? ll2 : ll1;
        while (llt != NULL || c != 0) {
            if (llt == NULL) {
                tt->next = new ListNode(1);
                c = 0;
            }
            else {
                int v = llt->val + c;
                if (v >= 10) {
                    c = 1;
                    v = v - 10;
                }   
                else {
                    c = 0;
                }
                tt->next = new ListNode(v);
                llt = llt->next;
            }
            tt = tt->next;
        }
        return res;
    }
};