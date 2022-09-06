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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head, *last = head;
        if(head == NULL) return head;
        temp = temp -> next;
        last -> next = NULL;
        while(temp != NULL) {
            ListNode *copy = temp;
            temp = temp -> next;
            copy -> next = last;
            last = copy;
        }
        return last;
    }
};