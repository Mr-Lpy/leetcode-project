#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

class Solution {
public:
	//	4ms
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.empty()) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}
		std::string temp = strs[0];
		std::string result = "";
		for (int i = 0; i < temp.size(); ++i) {
			for (int j = 1; j < strs.size(); ++j) {
				if (i >= strs[j].size() || temp[i] != strs[j][i]) {
					return result;
				}
			}
			result += temp[i];
		}
		return result;
	}

	//	4ms
	std::string longestCommonPrefix2(std::vector<std::string>& strs) {
		if (strs.empty()) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}
		std::string temp = strs[0];
		for (int i = 0; i < temp.size(); ++i) {
			for (int j = 1; j < strs.size(); ++j) {
				if (i >= strs[j].size() || temp[i] != strs[j][i]) {
					return temp.substr(0, i);
				}
			}
		}
		return temp;
	}

	//	8ms
	std::string longestCommonPrefix3(std::vector<std::string>& strs) {
		if (strs.empty()) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}
		int index = 0;
		std::sort(strs.begin(), strs.end());
		int len = std::min(strs[0].size(), strs.back().size());
		while (index < len && strs[0][index] == strs.back()[index]) {
			index++;
		}
		return strs[0].substr(0,index);
	}
};


bool it(std::vector<std::string> param, std::string expect) {
	Solution s;
	std::string result = s.longestCommonPrefix(param);

	if (result == expect) {
		std::cout << "check " << " successed." << std::endl;
	}
	else {
		std::cout << "check " << " failed. expect " << expect << " but result " << result << std::endl;
	}
	return expect == result;
}


bool it2(std::vector<std::string> param, std::string expect) {
	Solution s;
	std::string result = s.longestCommonPrefix2(param);

	if (result == expect) {
		std::cout << "check " << " successed." << std::endl;
	}
	else {
		std::cout << "check " << " failed. expect " << expect << " but result " << result << std::endl;
	}
	return expect == result;
}

bool it3(std::vector<std::string> param, std::string expect) {
	Solution s;
	std::string result = s.longestCommonPrefix3(param);

	if (result == expect) {
		std::cout << "check " << " successed." << std::endl;
	}
	else {
		std::cout << "check " << " failed. expect " << expect << " but result " << result << std::endl;
	}
	return expect == result;
}

bool describe14(void) {
	it3({ "flower", "flow", "flight" }, "fl");
	it3({ "dog", "racecar", "car" }, "");
	it3({ "a", "a", "b" }, "");
	it3({ "aaa", "aa", "aaa" }, "aa");
	return true;
}