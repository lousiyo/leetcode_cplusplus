
#include <iostream>
#include <stack>

using std::cout;
using std::stack;

class MyQueue
{
    stack<int> ins;
    stack<int> outs;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        ins.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int res = peek();
        outs.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        if (outs.empty())
        {
            while (!ins.empty())
            {
                outs.push(ins.top());
                ins.pop();
            }
        }
        return outs.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
       return (ins.empty() && outs.empty()); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char const *argv[])
{
    MyQueue mq;
    mq.push(2);
    mq.push(1);
    mq.push(3);
    cout << mq.peek();
    cout << std::endl;
    cout << std::endl;
    stack<int> a;
    a.push(3);
    return 0;
}
