class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int hash[100001]={0};
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int repeating = -1;
        for(int i=1;i<=n;i++){
            if(hash[i]>=2){
                repeating = i;
            }
            if(repeating != -1){
                break;
            }
        }
        return repeating;
    }
};