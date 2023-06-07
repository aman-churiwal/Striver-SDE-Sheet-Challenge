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
    void deleteNode(ListNode* node) {
        ListNode *curr = node;
        ListNode *nextP = curr->next;
        swap(curr->val, nextP->val);
        curr->next = nextP->next;
    }
};