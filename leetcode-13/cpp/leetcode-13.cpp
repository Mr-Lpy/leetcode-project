#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "test.h"

class Solution {
public:
	int romanToInt(std::string s) {
		if (s.empty()) {
			return false;
		}
		std::map<char, int> mapRoman = {
			{ 'I', 1 }, { 'V', 5},
			{ 'X', 10 }, { 'L', 50 },
			{'C', 100},{'D', 500},
			{'M', 1000}};
		int n = s.size() - 1;
		int sum = mapRoman.find(s[n])->second;
		if (sum == 0) {
			return 0;
		}
		for (int i = n - 1; i >= 0; i--) {
			int temp = mapRoman.find(s[i])->second;
			int temp_last = mapRoman.find(s[i + 1])->second;
			if (temp == 0 || temp_last == 0) {
				return 0;
			}
			if (temp < temp_last) {
				sum -= temp;
				continue;
			}
			sum += temp;
		}
		return sum;
	}
	int romanToInt2(std::string s) {
		if (s.empty()) {
			return false;
		}
		std::vector<int> vecRomans(90);
		vecRomans['I'] = 1;
		vecRomans['V'] = 5;
		vecRomans['X'] = 10;
		vecRomans['L'] = 50;
		vecRomans['C'] = 100;
		vecRomans['D'] = 500;
		vecRomans['M'] = 1000;
		int n = s.size() - 1;
		int sum = vecRomans[s[n]];
		if (sum == 0) {
			return 0;
		}
		for (int i = n-1; i >= 0; --i) {
			int temp = vecRomans[s[i]];
			int temp_last = vecRomans[s[i + 1]];
			if (temp == 0 || temp_last == 0) {
				return 0;
			}
			if (temp < temp_last) {
				sum -= temp;
				continue;
			}
			sum += temp;
		}
		return sum;
	}
};

bool it(std::string param, int expect) {
	Solution s;
	int result = s.romanToInt(param);

	if (result == expect) {
		std::cout << "check " << param << " successed." << std::endl;
	}
	else {
		std::cout << "check " << param << " failed. expect " << expect << " but result " << result << std::endl;
	}
	return expect == result;
}

bool it2(std::string param, int expect) {
	Solution s;
	int result = s.romanToInt2(param);

	if (result == expect) {
		std::cout << "check " << param << " successed." << std::endl;
	}
	else {
		std::cout << "check " << param << " failed. expect " << expect << " but result " << result << std::endl;
	}
	return expect == result;
}


bool describe13(void) {
	it2("V", 5);
	it2("III", 3);
	it2("IV", 4);
	it2("IX", 9);
	it2("LVIII", 58);
	it2("MCMXCIV", 1994);
	return false;
}