/**
 * https://leetcode.com/problems/reverse-linked-list/description/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    // Non-recursive approach
    {
        ListNode *c1 = NULL, *c2;
        while(head)
        {
            c2 = head->next;
            head->next = c1;
            c1 = head;
            head = c2;
        }
        return c1;
    }

    ListNode* reverseList2(ListNode* head)
    // Recursive approach
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* next = reverseList2(head->next);
        head->next->next = head;
        head->next = NULL;
        return next;
    }
};