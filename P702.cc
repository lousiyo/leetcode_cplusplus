#include <queue>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

class KthLargest
{
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int len;

public:
    KthLargest(int k, vector<int> &nums)
    {
        len = k;
        if (nums.size())
        {
            for (auto const &i : nums)
            {
                if (pq.size() < k)
                {
                    pq.push(i);
                }
                else
                {
                    if (i > pq.top())
                    {
                        pq.pop();
                        pq.push(i);
                    }
                }
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > len)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 11, 134, 22, 12, 13};
    KthLargest *obj = new KthLargest(5, nums);
    cout << obj->add(5) << endl;
    cout << obj->add(99) << endl;
    delete (obj);
    return 0;
}
