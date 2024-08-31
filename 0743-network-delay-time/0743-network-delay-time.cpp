class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& vec: times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v,w});
        }
        int source = k;
        vector<int> res(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        res[source] = 0;
        pq.push({0, source});   // {dist,node}
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto& vec: adj[u]){
                int v = vec.first;
                int w = vec.second;
                
                if(w+dist < res[v]){
                    res[v]= w+dist;
                    pq.push({w+dist, v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            ans = max(ans,res[i]);
        }
        return ans ==INT_MAX ? -1 : ans;
    }
};