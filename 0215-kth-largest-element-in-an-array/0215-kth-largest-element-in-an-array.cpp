class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num:nums){
            pq.push(num);
        }
        int ele = 0;
        while(k--){
            ele = pq.top();
            pq.pop();
        }
        return ele;
    }
};