class MedianFinder{
public:
    priority_queue<int> maxleftpq;
    priority_queue<int,vector<int>,greater<int>> minrightpq;
    MedianFinder(){

    }
    void addNum(int num){
        if(maxleftpq.empty() || maxleftpq.top()>num){
            maxleftpq.push(num);
        }else{
            minrightpq.push(num);
        }
        if(maxleftpq.size()>minrightpq.size()+1){
            int ele = maxleftpq.top();
            maxleftpq.pop();
            minrightpq.push(ele);
        }else if(maxleftpq.size()<minrightpq.size()){
            int ele = minrightpq.top();
            minrightpq.pop();
            maxleftpq.push(ele);
        }
    }
    double findMedian(){
        if(maxleftpq.size()==minrightpq.size()){
            int ele1 = maxleftpq.top();
            int ele2 = minrightpq.top();
            double sum = (ele1+ele2)/2.0;
            return sum;
        }
        return maxleftpq.top();
    }
};
