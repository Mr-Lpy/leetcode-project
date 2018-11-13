/**
 * @param {number} x
 * @return {boolean}
 */
function isPalindrome(x) {
  if (x < 0) {
    return false;
  }
  if (x < 10) {
    return true;
  }
  let tempx = x;
  let reverse = 0;
  while (tempx) {
    reverse = reverse * 10 + tempx % 10;
    tempx = Math.floor(tempx / 10);
  }
  console.log(reverse);
  return x === reverse;
}

function isPalindrome2(x) {
  if (x < 0) {
    return false;
  }
  if (x < 10) {
    return true;
  }
  let str_num = x.toString();
  for (let i = 0; i < str_num.length/2; ++i) {
    if (str_num[i] != str_num[str_num.length - 1 - i]) {
      return false;
    }
  }
  return true;
}

console.log(isPalindrome2(-121));