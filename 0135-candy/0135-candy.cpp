class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n,1);
        for(int i=1;i<n;i++){ // left to right (compare w left)
            if(ratings[i]>ratings[i-1]){
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){ // right to left (compare with right)
            if(ratings[i]>ratings[i+1]){
                arr[i]=max(arr[i+1]+1,arr[i]);
            }
        }
        int total = 0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
        return total;
    }
};