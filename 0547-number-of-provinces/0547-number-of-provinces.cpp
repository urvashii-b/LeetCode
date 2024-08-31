// class Solution {
// private:
//     void dfs(unordered_map<int,vector<int>> &adj, int u, vector<bool> &vis){
//         vis[u]=true;
//         for(int& v: adj[u]){
//             if(!vis[v]){
//                 dfs(adj,v,vis);
//             }
//         }
//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<bool> vis(n, false);
//         unordered_map<int,vector<int>> adj;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(isConnected[i][j]==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         int provinces = 0;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(adj,i,vis);
//                 provinces++;
//             }
//         }
//         return provinces;
//     }
// };

// class Solution {
// private:
//     void dfs(vector<vector<int>> &isConnected, int u, vector<bool> &vis){
//         vis[u]=true;
//         int n = isConnected.size();
//         for(int v = 0; v<n; v++){
//             if(!vis[v] && isConnected[u][v]==1){
//                 dfs(isConnected,v,vis);
//             }
//         }
//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<bool> vis(n, false);
//         int provinces = 0;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(isConnected,i,vis);
//                 provinces++;
//             }
//         }
//         return provinces;
//     }
// };

class Solution {
private:
    void bfs(vector<vector<int>> &isConnected, int u, vector<bool> &vis){
        int n = isConnected.size();
        queue<int> q;
        q.push(u);
        vis[u]=true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v=0; v<n; v++){
                if(!vis[v] && isConnected[u][v]==1){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(isConnected,i,vis);
                provinces++;
            }
        }
        return provinces;
    }
};