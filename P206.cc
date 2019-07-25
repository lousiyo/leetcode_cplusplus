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

//default private
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //three points
        ListNode *curr = head, *pre = NULL, *next = NULL;

        while (curr)
        {
            next = curr->next; 
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};

int main(int argc, char const *argv[])
{
    //test code
    ListNode l1(1), l2(2), l3(3), l4(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    Solution s;
    ListNode *last = s.reverseList(&l1);
    while (last != NULL)
    {
        std::cout << last->val << " ";
        last = last->next;
    }
    std::cout << std::endl;
    
    return 0;
}
