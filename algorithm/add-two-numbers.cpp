/* Description
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int flag = 0;
        ListNode head(0), *p = &head;
        while(l1 || l2 || flag)
        {   
            flag = ((l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0)) + flag;
            p -> next = new ListNode(flag % 10);
            flag /= 10;
            p = p -> next;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        return head.next;
    }
};