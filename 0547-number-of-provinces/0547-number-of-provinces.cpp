class Solution {
private:
    void dfs(int node, unordered_map<int,vector<int>> &adj, vector<bool> &vis){
        if(vis[node]==true) return;
        vis[node]=true;
        for(int &neighbour: adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        int V = isConnected.size();
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(isConnected[u][v]==1 && u!=v){
                    adj[u].push_back(v);
                }
            }
        }
        vector<bool> vis(V,false);
        int components = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                components++;
                dfs(i,adj,vis);
            }
        }
        return components;
    }
};