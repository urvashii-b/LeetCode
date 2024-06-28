class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> edge_cnt(n,0);
        for(const auto&road: roads){
            edge_cnt[road[0]]++;
            edge_cnt[road[1]]++;
        }
        sort(edge_cnt.begin(), edge_cnt.end());
        long long res=0;
        for(int i=0;i<n;i++){
            res+=static_cast<long long>(i+1)*edge_cnt[i];
        }
        return res;
    }
};