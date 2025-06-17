class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        priority_queue<int> maxHeap; // max-heap for smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for larger half

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            // Insert into correct heap
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Calculate median
            double res = 0.0;
            if (maxHeap.size() == minHeap.size()) {
                res = (maxHeap.top() + minHeap.top()) / 2.0;
            } else {
                res = maxHeap.top() * 1.0;
            }

            ans.push_back(res);
        }

        return ans;
    }
};
