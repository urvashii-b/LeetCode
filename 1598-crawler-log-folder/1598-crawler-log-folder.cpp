class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(const auto& cur: logs){
            if(cur=="../"){
                cnt = max(0,cnt-1);
            }else if(cur!="./"){
                cnt++;
            }
        }
        return cnt;
    }
};