class Solution {
private:
    bool topologicalSort(int n, unordered_map<int,vector<int>> &adj, vector<int> &inDegree){
        queue<int> q;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(inDegree[i]==0){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto& v: adj[u]){
                inDegree[v]--;
                
                if(inDegree[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        return (cnt==n);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // if topological sort - no cycle - courses can be scheduled
        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(numCourses,0);
        for(auto& vec: prerequisites){
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        return topologicalSort(numCourses, adj, inDegree);
    }
};