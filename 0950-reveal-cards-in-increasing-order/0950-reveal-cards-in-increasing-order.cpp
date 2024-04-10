class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n);
        bool skip = false; // revealing first card
        int indexInDeck = 0;
        int indexInResult = 0;
        
        sort(deck.begin(),deck.end());
        
        while(indexInDeck<n){
            if(res[indexInResult]==0){
                if(!skip){
                    res[indexInResult]=deck[indexInDeck];
                    indexInDeck++;
                }
                skip = !skip;
            }
            indexInResult = (indexInResult+1)%n;
        }
        return res;
    }
};