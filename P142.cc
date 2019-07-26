/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /**
         * using set struct
         */
       // set<ListNode*> lns;
       // ListNode *curr = head;
       // while (curr) {
       //     auto res = lns.insert(curr);
       //     if(!res.second)
       //         return *(res.first);
       //     curr = curr->next;
       // }


       /**
        * Floye's cycle detction algorithm
        */
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode *fast= head, *slow = head;
        bool isCycle = false;
        while (fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                isCycle = true;
                break;
            }
        }
        //cout << isCycle << endl;
        if(!isCycle)
            return NULL;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1(3), l2(2), l3(0), l4(-4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l2;
    Solution s;
    cout << s.detectCycle(&l1)->val << endl;
    return 0;
}
