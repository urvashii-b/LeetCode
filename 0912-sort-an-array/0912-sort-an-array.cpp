class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>> minpq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            minpq.push(nums[i]);
        }
        for(int i=0;i<n;i++){
            int ele = minpq.top();
            minpq.pop();
            nums[i]=ele;
        }
        return nums;
    }
};