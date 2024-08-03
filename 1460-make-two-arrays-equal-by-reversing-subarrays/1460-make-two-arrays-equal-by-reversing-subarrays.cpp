class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target==arr){
            return true;
        }
        unordered_map<int,int> mpp;
        for(int num:target){
            mpp[num]++;
        }
        for(int num:arr){
            mpp[num]--;
        }
        for(auto it: mpp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};