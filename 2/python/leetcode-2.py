def reverse(x):
  """
  :type x: int
  :rtype: int
  """
  ret = 0;
  while x:
    temp = ret * 10 + x % 10;
    ret = temp;
    x = int(x / 10);
  if ret> 2147483647 or ret < -2147483648:
    return 0;
  return ret;

  num = 123;
  reversedNum = reverse(num);
  print('before reverse: %d and after reversed: %d' % (num, reversedNum));
