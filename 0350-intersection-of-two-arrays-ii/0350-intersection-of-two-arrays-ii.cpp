class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        1. BRUTE
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        int vis[1000]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j] && vis[j]==0){
                    ans.push_back(nums1[i]);
                    vis[j]=1;
                    break;
                }
                if(nums2[j]>nums1[i]){
                    break;
                }
            }
        }
        return ans;
        
        2. OPTIMAL
        */
        int i=0,j=0, n=nums1.size(), m=nums2.size();
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};