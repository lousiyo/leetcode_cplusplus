#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        size_t size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                int find_it = target - nums[i] - nums[j];
                int front = j + 1;
                int back = size - 1;

                while (front < back)
                {
                    if (nums[front] + nums[back] > find_it)
                        --back;
                    else if (nums[front] + nums[back] < find_it)
                        ++front;
                    else
                    {
                        vector<int> vec{nums[i], nums[j], nums[front], nums[back]};
                        res.push_back(vec);

                        //deal front dup
                        while ((front < back) && vec[2] == nums[front])
                            ++front;
                        while (front < back && vec[3] == nums[back])
                            --back;
                        //deal back dup
                    }
                }

                //deal dup
                while (j + 1 < size && nums[j] == nums[j + 1])
                    ++j;
            }

            //deal dup
            while (i + 1 < size && nums[i] == nums[i + 1])
                ++i;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{

    vector<int> vec = {0,0,4,-2,-3,-2,-2,-3};
    Solution s;
    vector<vector<int>> res = s.fourSum(vec,-1);
    for (auto const &i : res)
    {
        for (auto &j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    return 0;
}
