/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (40.44%)
 * Total Accepted:    214.9K
 * Total Submissions: 528.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */
/*
1.峰值就是比相邻的数都大的值？找到返回下标?
2.找不到呢？返回-1？
3.多个峰值？随便返回一个？
4.相邻两个数会重复吗？
5.nums[-1],nums[n]可以看成是负无穷吗？那么nums[0],nums[n-1]有可能是峰值了
[1]  => 1
[1,2] => 较大数
[3,2,1] => 3
6.如果mid在谷点，不好决定舍弃哪一半
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
	int right = nums.size() - 1;//remember denife int
	
	while (left <= right) {
		int mid = left + (right - left >> 1);
		
		bool is_greater_than_left = mid - 1 < 0 ? true : nums[mid] > nums[mid - 1];
		bool is_less_than_right = mid + 1 >= nums.size() ? false : nums[mid] < nums[mid + 1];//if n not defined, remember use nums.size()
		
		if (is_greater_than_left && is_less_than_right) {
			left = mid + 1;
		} else if (!is_greater_than_left && !is_less_than_right) {
			right = mid - 1;
		} else if (is_greater_than_left && !is_less_than_right) {
			return mid;
		} else {
			right = mid - 1;
		}
	}
	return -1; // remember to return
    }
};


