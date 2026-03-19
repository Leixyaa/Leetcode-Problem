class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      int m = matrix[0].size();
      int left = 0;
      int right = m * n - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        int row = mid / m;
        int column = mid % m;
        int t = matrix[row][column];
        if (t == target) {
          return true;
        } else if (t < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      return false;
    }
};