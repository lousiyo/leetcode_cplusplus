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

using std::cout;
using std::endl;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) {}
};

class Solution {
public:
 ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)   
            return head;
        int size = 0;
        ListNode preflag(-1);
        preflag.next = head;
        ListNode *curr = &preflag;
        ListNode *next, *pre = &preflag;
        while ((curr = curr->next))
        {
            ++size;
        }
        cout << size << endl; 
        while (size >= k)
        {
            curr = pre->next;
            next = curr->next;
            for(int i = 1; i < k ; ++i){
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            pre = curr;
            size -= k;
        }
        return preflag.next;
 } 
};

int main(int argc, char const *argv[])
{
    ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
    l1.next = &l2;
    //l2.next = &l3;
    //l3.next = &l4;
    //l4.next = &l5;
    Solution s;
    ListNode *res = s.reverseKGroup(&l1,2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

     
    return 0;
}
