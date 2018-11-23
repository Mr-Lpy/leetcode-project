/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (strs.length == 0) {
    return '';
  }
  if (strs.length == 1) {
    return strs[0];
  }
  let temp = strs[0];
  let result = '';
  for (let i = 0; i < temp.length; ++i) {
    for (let j = 1; j < strs.length; ++j) {
      if (i >= strs[j].length || temp[i] !== strs[j][i]) {
        return result;
      }
    }
    result += temp[i];
  }
  return result;
};

let ret = longestCommonPrefix(['flower', 'fl']);
console.log(ret);
ret = longestCommonPrefix(['aaa', 'aa', 'aaa']);
console.log(ret);

ret = longestCommonPrefix(["aca", "cba"]);
console.log(ret);