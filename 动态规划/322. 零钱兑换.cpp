
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      sort(coins.begin(), coins.end());
      vector<int> f(amount + 1, INT_MAX / 2);
      f[0] = 0;
      for (int i = 1; i <= amount; i++) {
        for (auto j : coins) {
          if (i < j) break;
          f[i] = min(f[i], f[i - j] + 1);
        }
      }
      if (f[amount] >= INT_MAX / 2) return -1;
      return f[amount];
    }
};