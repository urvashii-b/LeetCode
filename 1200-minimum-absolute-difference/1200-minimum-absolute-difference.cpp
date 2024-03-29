class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        vector<int> dummy;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            int a = arr[i+1]-arr[i];
            dummy.push_back(a);
        }
        int minn = INT_MAX;
        for(int i=0;i<dummy.size();i++){
            minn = min(minn,dummy[i]);
        }
        for(int i=0;i<dummy.size();i++){
            vector<int> level;
            if(dummy[i]==minn){
                level.push_back(arr[i]);
                level.push_back(arr[i+1]);
            }
            else{
                continue;
            }
            ans.push_back(level);
        }
        return ans;
    }
};