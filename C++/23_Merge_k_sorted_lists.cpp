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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode *ans = new ListNode(0);
        ListNode *tt = ans;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        while(pq.size() != 0) {
            tt->next = pq.top();
            tt = tt->next;
            pq.pop();
            if (tt->next != NULL) {
                pq.push(tt->next);
            }
        }
        return ans->next;
    }
};
