class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size();
      int m = nums2.size();

      if (n > m) {
        swap(nums1, nums2);
        swap(n, m);
      }

      nums1.insert(nums1.begin(), INT_MIN);
      nums2.insert(nums2.begin() ,INT_MIN);
      nums1.push_back(INT_MAX);
      nums2.push_back(INT_MAX);

      int pos = (m + n + 1) / 2;

      for (int i = 0; i <= (m + n + 1) / 2; i++) {
        int j = (m + n + 1) / 2 - i;

        if (nums1[i] <= nums2[j + 1] && nums1[i + 1] >= nums2[j]) {
          if ((m + n) % 2 == 0) {
            return (max(nums1[i], nums2[j]) + min(nums1[i + 1], nums2[j + 1])) / 2.0;
          } else {
            return max(nums1[i], nums2[j]);
          }
        }
      }
      return 0;
    }
};