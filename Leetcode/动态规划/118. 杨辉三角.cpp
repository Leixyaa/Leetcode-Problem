class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans;
      vector<int> ansi;
      for (int i = 0; i < numRows; i++) {
        vector<int> ansi(i + 1, 1);
        for (int p = 0; p < i - 1; p++) {
          ansi[p + 1] = ans.back()[p] + ans.back()[p + 1]; 
        }
        ans.emplace_back(ansi);
      }
      return ans;
    }
};