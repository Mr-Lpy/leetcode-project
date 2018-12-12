/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  if (s.length === 0) {
    return true;
  }
  if (s.length % 2 !== 0) {
    console.log('in s.length % 2 !== 0');
    return false;
  }
  console.log('in for');
  let stack = [];
  let len = s.length;
  for (let i = 0; i < len; ++i) {
    switch (s[i]) {
      case '(':
      case '[':
      case '{': {
        stack.push(s[i]);
        console.log(stack);
        break;
      }
      case ')': {
        console.log('case )');
        if (stack.length === 0 || stack[stack.length - 1] !== '(') {
          console.log(stack[stack.length - 1]);
          return false;
        }
        console.log('case ) end');
        stack.pop();
        break;
      }
      case ']': {
        if (stack.length === 0 || stack[stack.length - 1] !== '[') {
          return false;
        }
        stack.pop();
        break;
      }
      case '}': {
        if (stack.length === 0 || stack[stack.length - 1] !== '{') {
          return false;
        }
        stack.pop();
        break;
      }
      default:
        break;
    }
  }
  console.log(stack.length);
  return stack.length === 0;
};

var isValid2 = function (s) {
  if (s.length === 0) {
    return true;
  }
  if (s.length % 2 !== 0) {
    return false;
  }
  let right = [];
  for (let i = 0; i < s.length; ++i) {
    if (s[i] === '(') {
      right.push(')');
      continue;
    }
    if (s[i] === '[') {
      right.push(']');
      continue;
    }
    if (s[i] === '{') {
      right.push('}');
      continue;
    }
    if (right.pop() !== s[i]) {
      return false;
    }
  }
  return right.length === 0;
}

let ret = isValid2('()');
console.log(ret);

ret = isValid2('()[]{}');
console.log(ret);

ret = isValid2('(]');
console.log(ret);

ret = isValid2('([)]');
console.log(ret);

ret = isValid2('{[]}');
console.log(ret);