class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      for (auto i : nums) {
        sum += i;
      }

      if (sum % 2 == 1) return false;
      sum /= 2;

      vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
      auto dfs = [&] (this auto&& dfs ,int i, int num)->bool {
        if (num == sum) return true;
        if (i >= n || num > sum) return false;

        int& ret = memo[i][num];

        if (ret != -1) return ret;

        return ret = (dfs(i + 1, num) || dfs(i + 1, num + nums[i]));
      };

      return dfs(0, 0);
    }
};