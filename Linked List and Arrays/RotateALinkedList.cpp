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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return NULL;
        ListNode *curr = head;
        int n = 0;
        while (curr)
        {
            n++;
            curr = curr->next;
        }

        k = k % n;
        if (k == 0)
            return head;
        curr = head;
        int i;
        for (i = 0; i < n - k - 1; i++)
        {
            curr = curr->next;
        }
        ListNode *ans = curr->next;
        ListNode *temp = curr;
        for (; i < n - 1; i++)
            temp = temp->next;
        temp->next = head;
        curr->next = NULL;

        return ans;
    }
};