/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	std::vector<int> result;
    	std::map<int, int> index;

    	for (int i = 0; i < nums.size(); i++) {
    		index[nums[i]] = i;
    	}

    	for (int i = 0; i < nums.size(); i++) {
    		int complement = target - nums[i];
    		if (index.find(complement) != index.end() && index[complement] != i) {
    			result.push_back(i);
    			result.push_back(index[complement]);
    			break;
    		}
    	}

    	return result;
    }
};

int main()
{
	std::vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	//nums.push_back(15);
	int target = 6;

	Solution solution;
	std::vector<int> result = solution.twoSum(nums, target);
	if (result.size() > 0) {
		std::cout<<result[0]<<std::endl;
		std::cout<<result[1]<<std::endl;
	}
}