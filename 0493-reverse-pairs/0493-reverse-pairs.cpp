#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high){
        if(low>=high) return 0;
        int mid = (high+low)/2;
        int inv = mergeSort(nums, low, mid);
        inv+=mergeSort(nums, mid+1, high);
        inv+=merge(nums,low,mid,high);
        return inv;
    }
    int merge(vector<int>& nums, int low, int mid, int high){
        int pairs = 0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2LL*nums[j]){
                j++;
            }
            pairs+=j-(mid+1);
        }
        int left = low, right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        /* 
        1. Brute Force 
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>2*nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
        */
       return mergeSort(nums, 0, nums.size()-1);
    }
};