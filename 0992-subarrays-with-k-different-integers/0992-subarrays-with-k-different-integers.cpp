class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), lnear=0, lfar=0, ans=0;
        map<int, int> mpp;
        for(int r = 0;r<n;r++){
            mpp[nums[r]]++;
           
            while(mpp.size()>k){
                mpp[nums[lnear]]-=1;
                if(mpp[nums[lnear]]==0)
                    mpp.erase(nums[lnear]);
                lnear+=1;
                lfar = lnear;
            }
            
            while(mpp[nums[lnear]]>1){
                mpp[nums[lnear]]-=1;
                lnear++;
            }
            
            if(mpp.size()==k){
                ans+=lnear-lfar+1;
            }
        }
        return ans;
    }
};