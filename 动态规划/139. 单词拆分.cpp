class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<int> memo(s.size(), -1);
      auto dfs = [&](this auto&& dfs, int i)->int {
        if (i == s.size()) return 1;
        int& res = memo[i];
        if (res != -1) return res;
        for (auto si : wordDict) {
          if (s.size() < si.size() || s.substr(i, si.size()) != si) {
            continue;
          } else if (s.substr(i, si.size()) == si) {
            res = dfs(i + si.size());
            if (res) return res;
          }
        }
        return res = 0;
      };
      return dfs(0);
    }
};