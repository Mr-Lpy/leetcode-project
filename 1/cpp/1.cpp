//
//  main.cpp
//  Test
//
//  Created by lpy on 2018/10/30.
//  Copyright © 2018 lpy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> indexs;
        int last1 = -1;
        int last2 = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (last1 == nums[i]) {
                continue;
            }
            for (int j = i+1; j < nums.size(); ++j) {
                if (last2 == nums[j] || nums[i] + nums[j] != target) {
                    continue;
                }
       
                indexs.push_back(i);
                indexs.push_back(j);
                last1 = nums[i];
                last2 = nums[j];
            }
        }
        return indexs;
    }
    std::vector<int> twoSum2(std::vector<int>& nums, int target) {
        std::vector<int> indexs;
        int last = -1;
        for (int i = 0; i < nums.size(); ++i) {
//            if (last == nums[i]) {
//                continue;
//            }
            last = nums[i];
            int find = target - nums[i];
            
            std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), find);
            if (it == nums.end()) {
                continue;
            }
            std::cout << "find: " << find << " find " << *it << std::endl;
            auto index = std::distance(std::begin(nums), it);
            if (index == i) {
                continue;
            }
            indexs.push_back(i);
            indexs.push_back((int)index);
        }
        //  去重
        std::sort(indexs.begin(), indexs.end());
        indexs.erase(std::unique(indexs.begin(), indexs.end()), indexs.end());
        return indexs;
    }
    
    std::vector<int> twoSum3(std::vector<int>& nums, int target) {
        std::vector<int> indexs;
        std::map<int, int> mapIndex;
        int index = -1;
        for (auto i : nums) {
            index++;
            if (mapIndex.find(target - i) == mapIndex.end()) {
                mapIndex[i] = index;
            } else {
                indexs = {mapIndex[target - i], index};
                break;
            }
        }
        return indexs;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<int> nums = {3,7,2,8,15};

    Solution s;
    std::vector<int> indexs = s.twoSum3(nums, 10);
    for (auto i : indexs) {
        std::cout << i << std::endl;
    }
    return 0;
}
