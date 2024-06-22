class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0, cnt = 0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){ // converting to binary
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem = prefixSum-k;
            cnt+=mpp[rem];
            mpp[prefixSum]++;
        }
        return cnt;
    }
};