class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      vector<int> f_max(n + 1, 1);
      vector<int> f_min(n + 1, 1);
      f_max[0] = nums[0];
      f_min[0] = nums[0];
      int maxi = INT_MIN;
      for (int i = 1; i < n; i++) {
        f_max[i] = max({nums[i], f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]});
        f_min[i] = min({nums[i], f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]});
        maxi = max(maxi, f_max[i]);
      } 
      return maxi;
    }
};