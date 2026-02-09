class MedianFinder {
    //maxH will have equal or 1 more element compared to minH
    priority_queue<int> maxH; //lower numbers
    priority_queue<int, vector<int>, greater<int>> minH; //higher numbers
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        int tp = maxH.top();
        maxH.pop();
        minH.push(tp);
        if (minH.size() > maxH.size()){
            tp = minH.top();
            minH.pop();
            maxH.push(tp);
        }
    }
    
    double findMedian() {
        if (maxH.size() == minH.size()) return (maxH.top() + minH.top())/2.0;
        return maxH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */