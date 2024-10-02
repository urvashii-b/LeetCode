class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mpp;
        vector<int> ans(arr);
        int rank = 1;
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++){
            if(i>0 && ans[i]>ans[i-1]){
                rank++;
            }
            mpp[ans[i]]=rank;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};