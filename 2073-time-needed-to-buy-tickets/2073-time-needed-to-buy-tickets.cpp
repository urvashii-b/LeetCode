class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        int time=0;
        while(!q.empty()){
            time++;
            int front = q.front();
            q.pop();
            tickets[front]--;
            if(k==front && tickets[front]==0){
                return time;
            }
            if(tickets[front]!=0){
                q.push(front);
            }
        }
        return time;
    }
};