#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::deque;
using std::endl;
using std::vector;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> deq;
        size_t n = nums.size();
        if (n == 0)
            return res;
        for (int i = 0; i < n; ++i)
        {
            if (!deq.empty())
            {
                if (i - deq.front() >= k)
                    deq.pop_front();
                while (!deq.empty() && nums[i] >= nums[deq.back()])
                    deq.pop_back();
            }
            deq.push_back(i);
            if (i + 1 >= k)
                res.push_back(nums[deq.front()]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vc = {1, -1};
    Solution s;
    vector<int> res = s.maxSlidingWindow(vc, 1);
    cout << "*****************" << endl;
    for (const auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
