class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int> memo(n, 0);
      auto dfs = [&](this auto&& dfs, int i)->int {
        int& res = memo[i];
        if (res > 0) return res;
        for (int p = 0; p < i; p++) {
          if (nums[p] < nums[i]) {
            res = max(res, dfs(p));
          }
        }
        res++;
        return res;
      };
      int ans = 0;
      for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
      }
      return ans;
    }
};