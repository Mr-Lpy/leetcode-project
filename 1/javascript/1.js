/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  let results = [];
  let mapRet = new Map();
  for (let i in nums) {
    if (!mapRet.has(target - nums[i])) {
      mapRet.set(nums[i], i);
    } else {
      results = [Number(mapRet.get(target - nums[i])), Number(i)];
      break;
    }
  }
  return results;
};

function printMap(map) {
  for (let item of map) {
    console.log(item[0] + ' : ' + item[1] );
  }
}

let indexs = twoSum([2,7,11,15], 9);
for (let i in indexs) {
  console.log(indexs[i]);
}