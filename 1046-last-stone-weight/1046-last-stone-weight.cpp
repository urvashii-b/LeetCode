class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> maxheap;
        for(int i:stones){
            maxheap.push(i);
        }
        while(maxheap.size()>1){
            int a = maxheap.top();
            maxheap.pop();
            int b = maxheap.top();
            maxheap.pop();
            if(a!=b){
                int ele = a-b;
                maxheap.push(ele);
            }else{
                maxheap.push(0);
            }
        }
        return maxheap.top();
    }
};