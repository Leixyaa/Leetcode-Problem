class Solution {
public:
    int jump(vector<int>& nums) {
      int pos_arrive;
      int n = nums.size();
      if (n == 1) return 0;
      int ans = 1;
      pos_arrive = nums[0];
      int pos = 0;
      while (pos < pos_arrive && pos_arrive < n - 1) {
        int next_pos = 0;
        int pos_n = pos_arrive;
        for (int i = pos + 1; i <= pos_n; i++) {
          if (nums[i] + i > pos_arrive) {
            next_pos = i;
            pos_arrive = nums[i] + i;
          }
        }
        pos = next_pos;
        ans++;
      }  
      return ans;
    }
};