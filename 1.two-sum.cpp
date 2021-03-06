/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (39.83%)
 * Total Accepted:    1.3M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */

/*
[1,2,3,5,8,6,4,10]  target:14

i=0 nums[i] == 1   [i+1,n-1]  nums[j] == target-nums[i]=13    i+1 <= j <= n-1 return i,j
0 <= i <= n-2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(target - nums[i]) != hash.end()) {
			res.push_back(i);
			res.push_back(hash[target - nums[i]]);
			break;
		} else {
			hash[nums[i]] = i;
		}
	}   
	return res;
    }
};
