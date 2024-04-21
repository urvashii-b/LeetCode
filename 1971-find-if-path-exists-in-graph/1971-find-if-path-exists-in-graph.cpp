class Solution {
private:
    bool dfs(int source, int destination, unordered_set<int> &vis, unordered_map<int, vector<int>> &graph){
        if (source == destination){
            return true;
        }
        vis.insert(source);
        for (int i: graph[source]){
            if (vis.find(i)==vis.end()){
                if(dfs(i,destination,vis,graph)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(const auto&edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        unordered_set<int> vis;
        return dfs(source, destination, vis, graph);
    }
};