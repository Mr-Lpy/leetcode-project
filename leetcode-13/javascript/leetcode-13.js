/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  if (s == '') {
    return 0;
  }
  let roman = [];
  roman['I'] = 1;
  roman['V'] = 5;
  roman['X'] = 10;
  roman['L'] = 50;
  roman['C'] = 100;
  roman['D'] = 500;
  roman['M'] = 1000;
  let n = s.length - 1;
  let sum = roman[s[n]];
  for (let i = n - 1; i >= 0; --i) {
    let temp = roman[s[i]];
    let last = roman[s[i + 1]];
    if (temp < last) {
      sum -= temp;
      continue;
    }
    sum += temp;
  }

  return sum;
};

let sum = romanToInt('MCMXCIV');