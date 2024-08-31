class Solution {
private:
    bool checkBipartiteDFS(vector<vector<int>>& graph, int n, vector<int> &color, int currentColor, int u){
        color[u] = currentColor;
        for(int& v: graph[u]){
            if(color[v]==color[u]){
                return false;
            }
            if(color[v]==-1){
                int colorOfV = 1 - currentColor;
                color[v]=colorOfV;
                if(checkBipartiteDFS(graph, n, color, colorOfV, v)==false){
                    return false;
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
                if(checkBipartiteDFS(graph,n,color,1,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};