class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for (auto i : nums) {
        sum += i;
      }
      if (sum % 2 != 0) return false;
      sum /= 2;
      int n = nums.size();
      vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
      auto dfs = [&](this auto&& dfs, int i, int s)->bool {
        if (i < 0) return false;
        int& res = memo[i][s];
        if (res != -1) return res;
        if (s == nums[i]) return res = true;
        if (s < nums[i]) return res = dfs(i - 1, s);
        return res = dfs(i - 1, s) || dfs(i - 1, s - nums[i]);
      };
      return dfs(n - 1, sum);
    }
};