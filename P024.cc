

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <cstdio>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        //inspired by StefanPochmann
        ListNode **p = &head;
        ListNode *a, *b;
        //when a and b not null 
        while ((a = *p) && (b = a->next))
        {
           a->next = b->next;
           b->next = a;
           *p = b;
           p = &(a->next); 
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1(1), l2(2), l3(3), l4(4);
    Solution s;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    ListNode *last = s.swapPairs(&l1);

    while (last != NULL)
    {
        std::cout << last->val << " ";
        last = last->next;
    }
    std::cout << std::endl;
    return 0;
}
