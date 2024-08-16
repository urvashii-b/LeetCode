class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>> sortedTasks;
        for(int i=0;i<n;i++){
            int start = tasks[i][0];
            int duration = tasks[i][1];
            int index = i;
            sortedTasks.push_back({start,duration,index});
        }
        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> res;
        long long time = 0;
        int i = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        while(i<n || !pq.empty()){
            if(pq.empty() && time<sortedTasks[i][0]){
                time = sortedTasks[i][0];
            }
            while(i<n && sortedTasks[i][0]<=time){
                pq.push({sortedTasks[i][1],sortedTasks[i][2]});
                i++;
            }
            pair<int,int> p=pq.top();
            pq.pop();
            time+=p.first;
            res.push_back(p.second);
        }
        return res;
    }
};