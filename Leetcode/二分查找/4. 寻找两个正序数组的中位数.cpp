class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
      if (a.size() > b.size()) {
        swap(a, b);
      }
      int m = a.size();
      int n = b.size();
      a.insert(a.begin(), INT_MIN);
      b.insert(b.begin(), INT_MIN);
      a.push_back(INT_MAX);
      b.push_back(INT_MAX);

      int left = 0;
      int right = (m + n + 1) / 2;
      while (true) {
        if (b[right] <= a[left + 1] && a[left] <= b[right + 1]) {
          int maxi = max(a[left], b[right]);
          int mini = min(a[left + 1], b[right + 1]);
          return (m + n) % 2 == 0 ? (maxi + mini) / 2.0 : maxi;
        }
        left++;
        right--;
      }
    }
};