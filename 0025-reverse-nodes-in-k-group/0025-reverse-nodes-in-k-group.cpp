/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* temp, int k) {
        ListNode *rhead = new ListNode;
        ListNode *prev = new ListNode;
        ListNode *first = new ListNode;
        ListNode *last = new ListNode;
        ListNode *nfirst = new ListNode;
        ListNode *nlast = new ListNode;
        ListNode *curr = new ListNode;
        ListNode *node = new ListNode;
        int f = 0;
        while(temp != nullptr) {
            int x = 0;
            node = temp;
            while(x < k && node) {
                x++;
                node = node -> next;
            }
            node = nullptr;
            if(x == k) {
                nfirst = temp;
                prev = nullptr;
                x = 0;
                while(x < k && temp) {
                    x++;
                    curr = temp;
                    temp = temp -> next;
                    if(prev) curr -> next = prev;
                    prev = curr;
                    if(x == k) nlast = curr;
                }
                curr = nullptr;
                if(!f) {
                    f = 1;
                    rhead = nlast;
                }
                if(first) {
                    first -> next = nlast;
                }
                nfirst -> next = nullptr;
                first = nfirst;
                last = nlast;
            } else {
                first -> next = temp;
                break;
            }
        }
        return rhead;
    }
};