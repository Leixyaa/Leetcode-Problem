class Solution {
public:
    vector<int> partitionLabels(string s) {
      unordered_map<char, int> idx;
      vector<int> ans;
      int n = s.size();
      for (int i = 0; i < n; i++) {
        char c = s[i];
        idx[c] = i;
      }
      int begin = 0;
      int end = -1;
      for (int i = 0; i < n; i++) {
        char c = s[i];
        if (idx[c] > end) {
          end = idx[c];
        }
        if (i == end) {
          ans.push_back(end - begin + 1);
          begin = end + 1;
        }
      }
      return ans;
    }
};