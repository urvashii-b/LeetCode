class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int maxJump = 0;
        for(int i=2;i<n;i++){
            maxJump = max(maxJump, stones[i]-stones[i-2]);
        }
        return max(maxJump, stones[1]-stones[0]);
    }
};