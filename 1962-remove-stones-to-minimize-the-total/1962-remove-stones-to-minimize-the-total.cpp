class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> maxpq;
        int sum = 0;
        for(int i:piles){
            sum+=i;
            maxpq.push(i);
        }
        for(int i=1;i<=k;i++){
            int element = maxpq.top();
            maxpq.pop();
            int remove = element / 2;
            sum-=remove;
            element-=remove;
            maxpq.push(element);
        }
        return sum;
    }
};