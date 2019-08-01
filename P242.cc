#include <string>
#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // map<char, int> m1, m2;
        //for (const auto &i : s)
        //m1[i] += 1;
        //for (const auto &i : t)
        //m2[i] += 1;
        //return m1 == m2;
        if (s.length() != t.length())
            return false;
        vector<int> freq(26, 0);
        for (auto const &i : s)
            ++freq[i - 'a'];
        for (auto const &i : t)
        {
            --freq[i - 'a'];
            if (freq[i - 'a'] < 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "rat";
    string s2 = "art";
    Solution s;
    cout << s.isAnagram(s1, s2) << endl;
    return 0;
}
