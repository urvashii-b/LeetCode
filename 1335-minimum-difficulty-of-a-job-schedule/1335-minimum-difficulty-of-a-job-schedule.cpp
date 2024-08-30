class Solution {
private:
    int solve(vector<int>& jobDifficulty, int n, int d, int index){
        if(d==1){
            int maxD = jobDifficulty[index];
            for(int i=index; i<n; i++){
                maxD = max(maxD, jobDifficulty[i]);
            }
            return maxD;
        }
        
        if(t[index][d]!=-1) return t[index][d];
        
        int maxD = jobDifficulty[index];
        int finalResult = INT_MAX;
        
        for(int i=index; i<=n-d; i++){
            maxD = max(maxD, jobDifficulty[i]);
            int res = maxD + solve(jobDifficulty,n,d-1,i+1);
            finalResult = min(finalResult, res);
        }
        return t[index][d] = finalResult;
    }
public:
    int t[301][11];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d>n) return -1;
        memset(t,-1,sizeof(t));
        return solve(jobDifficulty, n, d, 0);
    }
};