def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        indexs = [];
        dictIndex = {};
        for i in range(len(nums)):
            print('序号：%d 值: %d' % (i, nums[i]))
            if (target - nums[i]) not in dictIndex:
                dictIndex[nums[i]] = i;
            else:
                indexs = [dictIndex[target - nums[i]], i];
                break;
        return indexs;


indexs = twoSum([3,3], 6);
for i in indexs:
  print(i);