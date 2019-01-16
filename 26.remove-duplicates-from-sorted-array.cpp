/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (39.03%)
 * Total Accepted:    492.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
/*
[1,1,2,2,3,3,4,5] =>  [1,2,3,4,5] len==5
 
hashmap: map ; key:number;  value: appear times
i: cur_index
j: outer_bounder_index
i == j end

[1,5,2,4,3,3,2,1]
j :n -3
i : 3

map:{
    1:2,
    5:1,
    2:2,
}   
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
	int n = nums.size();
	int i = 0, j = 0;
	for (; i < n; i++) {
		if (map.find(nums[i]) == map.end()) {
			map[nums[i]] = 1;
			nums[j++] = nums[i];
		}
	}
	return j;
    }
};
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
	int n = nums.size();
	int i = 0, j = n;
	for (; i < n && i != j; i++) {
		if (map.find(nums[i]) != map.end()) {
			int tmp = nums[i];
			nums[i--] = nums[j-1];
			nums[j-1] = tmp;
			j--;
		} else {
			map[nums[i]] = 1;
		}
	}
	return i; 
    }
};
[1,2,1]
i:2
j:2
n:3
map{1:1,2:1}
*/
