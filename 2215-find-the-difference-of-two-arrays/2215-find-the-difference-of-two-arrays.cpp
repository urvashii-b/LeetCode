class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        /*
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        vector<int> diff1;
        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    flag = false;
                }
            }
            if(flag==true){
                diff1.push_back(nums1[i]);
            }
        }
        ans.push_back(diff1);
        n = nums2.size(), m=nums1.size();
        vector<int> diff2;
        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=0;j<m;j++){
                if(nums2[i]==nums1[j]){
                    flag = false;
                }
            }
            if(flag==true){
                diff2.push_back(nums2[i]);
            }
        }
        ans.push_back(diff2);
        return ans;
        */
        set<int> st1(nums1.begin(),nums1.end());
        set<int> st2(nums2.begin(),nums2.end());
        vector<int> v1;
        vector<int> v2;
        set_difference(st1.begin(),st1.end(),st2.begin(),st2.end(), back_inserter(v1));
        set_difference(st2.begin(),st2.end(),st1.begin(),st1.end(), back_inserter(v2));
        return {v1,v2};
    }
};