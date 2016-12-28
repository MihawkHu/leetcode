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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tt = head;
        int len = 0;
        while (tt != NULL) {
            tt = tt->next;
            ++len;
        }
        
        if (len < k) return head;
        
        tt = new ListNode(0);
        tt->next = head;
        for (int i = 0; i + k <= len; i += k) {
            ListNode *p1, *p2, *p3;
            p1 = tt->next;
            p2 = p1->next;
            p3 = p1;
            for (int i = 0; i < k - 1; ++i) {
                ListNode *temp = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = temp;
            }
            tt->next = p1;
            p3->next = p2;
            if (i ==0) {
                head = p1;
                ListNode *temp_tt = tt;
                tt = p3;
                delete temp_tt;
            }
            else {
                tt = p3;
            }
        }
        return head;
    }
};
