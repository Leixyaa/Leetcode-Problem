class MedianFinder {
public:
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
    MedianFinder() {
 
    }
    
    void addNum(int num) {
      int n = left.size();
      int m = right.size();
      if (n == m) {
        if (n == 0) {
          left.push(num);
          return;
        }
        if (num <= right.top()) {
          left.push(num);
        } else {
          int temp = right.top();
          right.pop();
          left.push(temp);
          right.push(num);
        }
      } else {
        if (num < left.top()) {
          int temp = left.top();
          left.pop();
          right.push(temp);
          left.push(num);
        } else {
          right.push(num);
        }
      }
    }
    
    double findMedian() {
      int n = left.size();
      int m = right.size();
      if (m == n) return (left.top() + right.top()) / 2.0;
      return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */