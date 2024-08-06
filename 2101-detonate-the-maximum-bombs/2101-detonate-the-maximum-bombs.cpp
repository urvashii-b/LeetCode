class Solution {
private:
    void dfs(int node, unordered_set<int> &vis, unordered_map<int,vector<int>> &adj){
        vis.insert(node);
        for(int &v: adj[node]){
            if(vis.find(v)==vis.end()){
                dfs(v,vis,adj);
            }
        }
    }
    
    int Bfs(int node, unordered_map<int,vector<int>> &adj){
        unordered_set<int> vis;
        queue<int> q;
        vis.insert(node);
        q.push(node);
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(int &v: adj[ele]){
                if(vis.find(v)==vis.end()){
                    q.push(v);
                    vis.insert(v);
                }
            }
        }
        return vis.size();
    }
public:
    typedef long long LL;
    int maximumDetonation(vector<vector<int>>& bombs) {
        /* 
        directed graph - build the adjacency list
        store which bombs will be detonated when one bomb is detonated
        traverse and then no of visited nodes = max cnt
        */
        int n = bombs.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                LL d1 = x2-x1;
                LL d2 = y2-y1;
                LL d = d1*d1+d2*d2;
                
                if((LL)r1*r1>=d){
                    adj[i].push_back(j);
                }
            }
        }
        int res=0;
        //unordered_set<int> vis;
        for(int i=0;i<n;i++){
            //dfs(i,vis,adj);
            int cnt = Bfs(i,adj);
            //int cnt = vis.size();
            res = max(res,cnt);
            //vis.clear();
        }
        return res;
    }
};