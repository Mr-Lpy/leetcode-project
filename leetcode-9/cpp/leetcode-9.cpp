#include <iostream>
#include <math.h>

class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
    {
      return false;
    }

    if (x < 10)
    {
      return true;
    }

    int nums[100];
    int index = 0;
    int tx = x;
    while (tx)
    {
      int temp = tx % 10;
      nums[index] = temp;
      index++;
      tx /= 10;
    }

    int reverse = 0;
    //        for (int i = 0; i < index; ++i) {
    //
    //            reverse += nums[i] * pow(10, index-1-i);
    //             std::cout << nums[i] << " - " << reverse << std::endl;
    //        }
    for (int i = index - 1; i >= 0; i--)
    {
      std::cout << "nums:" << nums[i] << " x: " << x << std::endl;
      if (x % 10 != nums[i])
      {
        return false;
      }
      x /= 10;
    }

    return true;
  }
};

int main(int argc, const char *argv[])
{
  // insert code here...
  std::cout << "Hello, World!\n";
  Solution s;
  std::cout << "rest: " << s.isPalindrome(1122113) << std::endl;
  return 0;
}