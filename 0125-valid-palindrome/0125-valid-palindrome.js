/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s=s.replace(/[^a-zA-Z0-9]/g,'').toLowerCase();
    let n = s.length;
    let start = 0, end = n-1;
    while(start<end){
        if(s[start]!==s[end]){
            return false;
        }else{
            start++;
            end--; 
        }
    }
    return true;
};