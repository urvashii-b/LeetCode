class MedianFinder{
public:
    priority_queue<int> left_maxpq;     // max heap
    priority_queue<int,vector<int>,greater<int>> right_minpq;       // min heap
    MedianFinder(){

    }
    void addNum(int num){
        if(left_maxpq.empty() || num<left_maxpq.top()){
            left_maxpq.push(num);
        }else{
            right_minpq.push(num);
        }
        if(left_maxpq.size()>right_minpq.size()+1){
            int ele = left_maxpq.top();
            left_maxpq.pop();
            right_minpq.push(ele);
        }else if(left_maxpq.size()<right_minpq.size()){
            int ele = right_minpq.top();
            right_minpq.pop();
            left_maxpq.push(ele);
        }
    }
    double findMedian(){
        if(left_maxpq.size()==right_minpq.size()){
            int ele1 = left_maxpq.top();
            int ele2 = right_minpq.top();
            double sum = (ele1+ele2)/2.0;
            return sum;
        }
        return left_maxpq.top();
    }
};
