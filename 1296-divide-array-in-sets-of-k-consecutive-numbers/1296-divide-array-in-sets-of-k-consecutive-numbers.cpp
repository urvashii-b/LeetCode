class Solution {
private:
    bool findSucc(vector<int> &nums ,int i, int n, int k){
        int next = nums[i]+1;
        nums[i]=-1;
        int cnt = 1;
        i++;
        while(i<n && cnt<k){
            if(next==nums[i]){
                next = nums[i]+1;
                cnt++;
                nums[i]=-1;
            }
            i++;
        }
        return cnt==k;
    }
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0){
            return false;
        }
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                if(!findSucc(nums, i, n, k)){
                    return false;
                }
            }    
        }
        return true;
    }
};