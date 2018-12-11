#include "test.h"
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
	bool isValid(std::string s) {
		if (s.length() % 2 != 0) {
			std::cout << "s.length = " << s.length() % 2;
			return 0;
		}

		if (s.empty()) {
			return true;
		}
		
		std::stack<char> parn;
		for (auto c : s) {
			switch (c){
			case '(':
			case '[':
			case '{':{
				parn.push(c);
				break;
			}
			case ')': {
				if (parn.empty() || parn.top() != '(') {
					return false;
				}
				parn.pop();
				break;
			}
			case ']': {
				if (parn.empty() || parn.top() != '[') {
					return false;
				}
				parn.pop();
				break;
			}
			case '}': {
				if (parn.empty() || parn.top() != '{') {
					return false;
				}
				parn.pop();
				break;
			}
			default:
				break;
			}
		}

		return parn.empty();
	}
};

bool it1(std::string param, bool expect) {
	Solution s;
	bool result = s.isValid(param);

	if (result == expect) {
		std::cout << "check " << param << " successed." << std::endl;
	}
	else {
		std::cout << "check " << param << " failed. expect " << expect << " but result " << result << std::endl;
	}
	return expect == result;
}

bool describe20() {
	it1("()", true);
	it1("()[]{}", true);
	it1("(]", false);
	it1("([)]", false);
	it1("{[]}", true);
	return true;
}