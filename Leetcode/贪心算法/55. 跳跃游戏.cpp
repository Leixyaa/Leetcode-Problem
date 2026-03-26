class Solution {
public:
    bool canJump(vector<int>& nums) {
      int pos_arrive = 0;
      int n = nums.size();
      pos_arrive = nums[0];
      for (int i = 1; i < n; i++) {
        if (i > pos_arrive) {
          return false;
        }
        pos_arrive = max(pos_arrive, nums[i] + i);
      }
      return true;
    }
};