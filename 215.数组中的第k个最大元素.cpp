/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> q;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        q.push(nums[i]);
      }
      for (int i = 0; i < k - 1; i++) {
        q.pop();
      }
      return q.top();
    }
};
// @lc code=end

