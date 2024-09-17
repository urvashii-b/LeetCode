class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        /*
        sum(Alice)-x+y = sum(Bob)-y+x;
        x-y = sum(Alice)-sum(Bob)/2
        */
        int sumAlice = 0, sumBob = 0;
        for(int candy: aliceSizes){
            sumAlice += candy;
        }
        for(int candy: bobSizes){
            sumBob += candy;
        }
        int diff = (sumAlice-sumBob)/2;
        unordered_set<int> bobSet(bobSizes.begin(),bobSizes.end());
        for(int x: aliceSizes){
            int y = x-diff;
            if(bobSet.count(y)){
                return {x,y};
            }
        }
        return {};
    }
};