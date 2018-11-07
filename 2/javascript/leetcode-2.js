/**
 * @param {number} x
 * @return {number}
 */
function reverse(x) {
  let flag = x < 0 ? -1 : 1;
  x = x * flag;
  let str = String(x);
  let ret = Number(str.split("").reverse().join(""))*flag;
  if (ret > 2147483647 || ret < -2147483648) {
    return 0;
  }
  return ret;
}

function reverse2(x) {
  let ret = 0;
  while (x) {
    temp = ret * 10 + parseInt(x % 10);
    ret = temp;
    if (ret > 2147483647 || ret < -2147483648) {
      return 0;
    }
    x = parseInt(x/10);
  }
  return ret;
}

let ret = reverse2(-123);
console.log(ret);