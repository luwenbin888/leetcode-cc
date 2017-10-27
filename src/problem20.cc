/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

    	//([{}])
        std::stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
        	char c = s[i];
        	switch (c) {
        		case '(':
        		case '[':
        		case '{':
        			stack.push(c);
        			break;
        		case '}':
        			if (stack.empty() || stack.top() != '{') {
        				return false;
        			}
        			else {
        				stack.pop();
        			}
        			break;
        		case ']':
        			if (stack.empty() || stack.top() != '[') {
        				return false;
        			}
        			else {
        				stack.pop();
        			}
        			break;
        		case ')':
        			if (stack.empty() || stack.top() != '(') {
        				return false;
        			}
        			else {
        				stack.pop();
        			}
        			break;
        	}
        }

        return stack.empty();
    }
};

int main()
{
	std::string s("([{}])");
	Solution solution;
	bool valid = solution.isValid(s);
	std::cout<<valid<<std::endl;
}