class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;
        int i=0;
        int n = expression.length();
        while(i<n){
            int currentNumerator = 0;
            int currentDenominator = 0;
            bool isNeg = (expression[i]=='-');
            if(expression[i]=='+' || expression[i]=='-'){
                i++;
            }
            while(i<n && isdigit(expression[i])){
                int val = expression[i]-'0';
                currentNumerator = (currentNumerator*10)+val;
                i++;
            }
            i++; // for the '/' symbol
            if(isNeg==true){
                currentNumerator *= -1;
            }
            while(i<n && isdigit(expression[i])){
                int val = expression[i]-'0';
                currentDenominator = (currentDenominator*10)+val;
                i++;
            }
            
            numerator = numerator*currentDenominator + currentNumerator*denominator;
            denominator = denominator*currentDenominator;
        }
        // simplied form i.e. 3/6 ---> 1/2
        int GCD = abs(__gcd(numerator,denominator));
        numerator /= GCD;
        denominator /= GCD;
        return to_string(numerator)+"/"+to_string(denominator);
    }
};