#include <iostream>
#include <string>
#include <stack>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stack;
class Solution {
public:
    bool isValid(string s) {

        /**
         * using map struct
         */
//        map<char, char> cmap = {{')','('}, {']', '['}, {'}', '{'} };
        //stack<char> cst;
        //for(auto c : s){
            //if(cmap[c]){
                //if(cst.empty()) return false;
                //if(cmap[c] == cst.top()){
                    //cst.pop();
                    //continue;
                //} else
                //return false;
            //} else
                //cst.push(c);
        //}
        //return cst.empty();


        /*
        switch */
        stack<char> cst;
        for(const char &c : s){
            switch (c)
            {
            case '(':
            case '[':
            case '{': cst.push(c);break;
            case ')':
                if(cst.empty() || cst.top() != '(') return false; else cst.pop(); break;
            case ']': if(cst.empty() || cst.top() != '[') return false; else cst.pop(); break;
            case '}': if(cst.empty() || cst.top() != '{') return false; else cst.pop(); break;
            default:
                break;
            }
        }
        return cst.empty();
    }
};


int main(int argc, char const *argv[])
{
    string s = "(){}[]";
    Solution ss;
    cout << ss.isValid(s) << endl; 
    return 0;
}
