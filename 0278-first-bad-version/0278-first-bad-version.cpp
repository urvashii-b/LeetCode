// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return 1;
        int low = 1, high = n;
        while(low<high){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)==false){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};