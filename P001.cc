#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::set;
using std::unordered_map;
using std::vector;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //force...
        //vector<int> res;
        //for (int i = 0; i < nums.size(); ++i)
        //{
        //for (int j = i + 1; j < nums.size(); ++j)
        //{
        //if (nums[i] + nums[j] == target)
        //{
        //res.push_back(i);
        //res.push_back(j);
        //}
        //}
        //}
        //return res;

        //hash map
        unordered_map<int, int> um;
        vector<int> res;
        int find_it;
        for (size_t i = 0; i < nums.size(); i++)
        {
            find_it = target - nums[i];
            if (um.find(find_it) != um.end())
            {
                res.push_back(um[find_it]);
                res.push_back(i);
            }
            um.insert(std::make_pair(nums[i], i));
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {3, 2, 4};
    Solution s;
    vector<int> res = s.twoSum(vec, 6);
    for (auto const &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
