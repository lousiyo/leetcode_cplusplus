#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int front = i + 1;
            int back = nums.size() - 1;
            int target = -nums[i];
            while (front < back)
            {
                if (target < 0)
                    break;
                if (nums[front] + nums[back] > target)
                    --back;
                else if (nums[front] + nums[back] < target)
                    ++front;
                else
                {
                    vector<int> ans{nums[i], nums[front], nums[back]};
                    res.push_back(ans);

                    //deal front dup
                    while (front < back && ans[1] == nums[front])
                        ++front;
                    //deal back dup
                    while (front < back && ans[2] == nums[back])
                        --back;
                }
            }
            //deal i dup
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {-1, -1, 0, 1, 2};
    Solution s;
    vector<vector<int>> res = s.threeSum(vec);
    for (auto const &i : res)
    {
        for (auto &j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    return 0;
}
