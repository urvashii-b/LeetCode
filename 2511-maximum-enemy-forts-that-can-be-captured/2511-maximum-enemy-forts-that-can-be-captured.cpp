class Solution {
public:
    int captureForts(vector<int>& forts) {
        // max number of 0s between 1 and -1
        int n = forts.size(), cnt = 0, curr = 0, maxi = 0;
        while(curr<n){
            int nxt = curr+1;
            if(forts[curr]!=0){
                while(nxt<n && forts[nxt]==0){
                    nxt++;
                }
            }
            if(nxt<n && forts[nxt]+forts[curr]==0){
                int capture = nxt-curr-1;
                maxi = max(maxi,capture);
            }
            curr=nxt;
        }
        return maxi;
    }
};