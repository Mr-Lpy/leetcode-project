#include <iostream>
#include <cmath>
class Solution {
public:
  int reverse(int x) {
    int ret = 0;
    
    while(x){
      int temp = ret * 10 + x % 10;
      if (ret != temp / 10) {
        //  已经溢出
        return 0;
      }
      ret = temp;
      x /= 10;
    }
    
    return ret;
  }
  int reverse2(int x) {
    int nums[100];
    int reverse[100];
    long ret = 0;
    int n = 0;
    
    while(x){
      /* code */
      nums[n++] = x % 10;
      x /= 10;
      std::cout << "x:::" << x << " nums:::" << nums[n-1] << " n:::" << n << std::endl;
    }
    int t = n;
    for (int i = 0; i < n; ++i) {
      ret += pow(10,--t)*nums[i];
      std::cout << "ret:::" << ret << " nums:::" << nums[i] << " t:::" << t << std::endl;
      if (ret > 0x7fffffff || ret < (signed int)0x80000000) {
        return 0;
      }
    }
    return ret;
  }
};

int main(void) {
  Solution s;
  int num = 1534236469;
  int ret = s.reverse2(num);
  std::cout << "before reverse::" << num << std::endl;
  std::cout << "reversed::" << ret << std::endl;
  return 0;
}