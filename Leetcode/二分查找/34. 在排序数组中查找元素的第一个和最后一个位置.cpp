class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      int left = 0;
      int right = n - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      int ans_right = right;
      left = 0;
      right = n - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      int ans_left = left;
      if (ans_left > ans_right) return {-1, -1};
      return {ans_left, ans_right};
    }
};