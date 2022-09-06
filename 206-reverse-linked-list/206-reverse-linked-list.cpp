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
    ListNode* rec(ListNode* root, ListNode* last) {
        if(root -> next == NULL) {
            root -> next = last;
            return root;
        }
        ListNode* nextTemp = root -> next;
        root -> next = last;
        return rec(nextTemp, root);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        return rec(head, NULL);
    }
};