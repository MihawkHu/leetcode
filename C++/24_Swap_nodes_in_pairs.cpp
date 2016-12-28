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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode* tt = head;
        while (tt->next != NULL && (tt == head || tt->next->next != NULL)) {
            if (tt == head) {
                head = tt->next;
                tt->next = head->next;
                head->next = tt;
            }
            else {
                ListNode *temp = tt->next;
                tt->next = temp->next;
                temp->next = temp->next->next;
                tt->next->next = temp;
                tt = temp;
            }
        }
        return head;
    }
};
