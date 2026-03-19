class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      stack<int> s;
      int maxi = 0;
      for (auto i : prices) {
        while (!s.empty() && i < s.top()) {
          s.pop();
          if (s.empty()) s.push(i);
        }
        if (s.empty()) s.push(i);
        maxi = max(maxi, i - s.top());
      }
      return maxi;
    }
};