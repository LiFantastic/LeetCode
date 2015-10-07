/*============================================================
Problem: Add Two Numbers
You are given two linked lists representing two non-negative 
numbers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and 
return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
============================================================*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyl3=new ListNode(0), *p1=l1, *p2=l2, *p3=dummyl3;
        int num, carry=0;
        
        while (p1 && p2) {
            num = p1->val+p2->val+carry;
            if (num > 9) {
                num -= 10;
                carry = 1;
            }
            else
            	carry = 0;
            p3->next = new ListNode(num);
            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }
        p1 = (p1) ? p1 : p2;
        while (p1) {
            num = p1->val+carry;
            if (num > 9) {
                num -= 10;
                carry = 1;
            }
            else
            	carry = 0;
            p3->next = new ListNode(num);
            p1 = p1->next;
            p3 = p3->next;
        }
        if (carry == 1)
            p3->next = new ListNode(1);
        
        p3 = dummyl3->next;
        delete dummyl3;
        return p3;
    }
};