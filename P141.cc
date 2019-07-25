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
#include <set>

using std::cout;
using std::endl;
using std::set;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        //        set<ListNode*> lset;
        //ListNode *ln = head;
        //while (ln)
        //{
        //auto res = lset.insert(ln);
        //if(!res.second)
        //return true;
        //ln = ln->next;
        //}
        //return false;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1(1), l2(2), l3(3);
    l1.next = &l2;
    l2.next = &l1;
    Solution s;
    cout << s.hasCycle(&l1) << endl;
    return 0;
}
