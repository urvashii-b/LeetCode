class Solution {
private:
    bool checkBipartiteBFS(vector<vector<int>>& graph, int n, vector<int> &color, int currentColor, int u){
        queue<int> q;
        q.push(u);
        color[u]=currentColor;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto& v: graph[u]){
                if(color[v]==color[u]){
                    return false;
                }
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(checkBipartiteBFS(graph,n,color,1,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};