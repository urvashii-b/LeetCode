class Solution {
private:
    bool hasCycle(int i, vector<int> &vis, unordered_map<int,vector<int>> &adj){
        vis[i]=1;
        for(int neighbor: adj[i]){
            if(vis[neighbor]==1){
                return true;
            }
            if(vis[neighbor]==0 && hasCycle(neighbor,vis,adj)){
                return true;
            }
        }
        vis[i]=2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj; //graph
        for(vector<int> &vec: prerequisites){
            int u = vec[0], v = vec[1];
            adj[v].push_back(u);    // if v then u
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0 && hasCycle(i,vis,adj)){
                return false;
            }
        }
        return true;
    }
};