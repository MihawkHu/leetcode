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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *l1 = head, *l2 = head;
        int cnt = 0;
        while (l2 != NULL) {
            cnt++;
            l2 = l2->next;
        }
        if (cnt == 0) return head;
        k = k % cnt;
        if (k == 0) return head;
        l2 = head;
        for (int i = 0; i < k; ++i) {
            l2 = l2->next;
        }
        while (l2->next != NULL) {
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *ans = l1->next;
        if (ans == NULL) ans = head;
        l1->next = l2->next;
        l2->next = head;
        return ans;
    }
};
