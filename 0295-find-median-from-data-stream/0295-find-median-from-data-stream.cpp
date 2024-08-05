class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top()>num){
            maxheap.push(num);
        }else{
            minheap.push(num);
        }
        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
            
        }else if(minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()){
            if(maxheap.empty()){
                return 0;
            }else{
                double avg = (maxheap.top()+minheap.top())/2.0;
                return avg;
            }
        }else{
            return maxheap.size()>minheap.size()?maxheap.top():minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */