class Solution {
public:
    int numberOfMatches(int n) {
        /* 
        log(n) time complexity
        int matches = 0;
        while(n!=1){
            if(n%2==0){ //even
                matches += (n/2);
                n = (n/2);
            }else{
                matches += ((n-1)/2);
                n = ((n-1)/2)+1;
            }
        }
        return matches;
        
        logic: if we have n teams, we will have 1 winner and n-1 will be eliminated 
        for 1 match we would have 2 teams and 1 would be eliminated
        so, no. of matches played = no. of people eliminated
        n-1 matches will be played
        */
        return n-1;
    }
};