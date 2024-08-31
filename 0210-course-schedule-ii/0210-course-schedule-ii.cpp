class Solution {
private:
    vector<int> topologicalSort(vector<int> &inDegree, int n, unordered_map<int,vector<int>> &adj){
        queue<int> q;
        vector<int> res;
        int cnt = 0;
        for(int i=0;i<n; i++){
            if(inDegree[i]==0){
                q.push(i);
                cnt++;
                res.push_back(i);
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
                    res.push_back(v);
                }
            }
        }
        if(cnt==n){
            return res;
        }else{
            return {};
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(numCourses,0);
        for(auto& vec: prerequisites){
            int u = vec[0], v = vec[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        return topologicalSort(inDegree,numCourses,adj);
    }
};