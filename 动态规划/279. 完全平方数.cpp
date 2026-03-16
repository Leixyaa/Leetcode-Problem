class Solution {
public:
    int numSquares(int n) {
      vector<int> f(n + 1, INT_MAX);
      f[1] = 1;
      f[0] = 0;
      for (int i = 2; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
          f[i] = min(f[i - j * j] + 1, f[i]);
        }
      }
      return f[n];
    }
};