class Solution {
private:
    bool canEatAllBananas(int k, vector<int>& piles, int h){
        int hours = 0;
        for(int pile:piles){
            int div = pile/k;
            hours+=div;
            if(pile%k!=0) hours++;
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1, right = 1000000000;
        while(left<right){
            int mid = left + (right-left)/2;
            if(canEatAllBananas(mid,piles,h)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};