class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        1. BRUTE FORCE - O(N^2)
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sel = nums[i];
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[j]==sel){
                    cnt++;
                }
            }
            if(cnt==1){
                return sel;
            }
        }
        return -1;
        
        2. HASHING - O(N)+O(N)+O(N)
        cannot use if large numbers/ negative numbers
        
        int n = nums.size();
        int hash[30001]={0};
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(hash[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
        
        3. MAP - O(N*logM) + O(M) where M (size of map) = N/2 + 1
        */
        int n = nums.size();
        // map<long long, int> mpp; ---> depending upon size of elements
        map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};