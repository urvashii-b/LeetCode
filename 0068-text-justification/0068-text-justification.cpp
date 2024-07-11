class Solution {
private:
    string findLine(int i, int j, int fills, int rem, vector<string> &words, int maxWidth){
        string line;
        for(int k=i;k<j;k++){
            line+=words[k];
            if(k==j-1){ // last word of the line - we have already added the spaces
                continue;
            }
            for(int z=1;z<=fills;z++){
                line+=" ";
            }
            if(rem>0){
                line+=" ";
                rem--;
            }
        }
        while(line.length()<maxWidth){
            line+=" ";
        }
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i=0, n = words.size();
        while(i<n){
            int j=i+1, spacecnt=0, lettercnt = words[i].length();
            while(j<n && words[j].length()+1+spacecnt+lettercnt<=maxWidth){
                lettercnt+=words[j].length();
                spacecnt++;
                j++;
            }
            int blankspace = maxWidth - lettercnt;
            int fills = spacecnt==0? 0 : blankspace / spacecnt;
            int rem = spacecnt==0? 0 : blankspace % spacecnt;
            if(j==n){   // last line - left justified
                fills = 1;
                rem = 0;
            }
            result.push_back(findLine(i,j,fills,rem,words, maxWidth));
            i=j;
        }
        return result;
    }
};