class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0 ;
        int digitProduct = 1 ;

        int number = n ;

        while(number != 0 ){
            int currentDigit = number % 10 ;
            number /= 10 ;

            digitSum += currentDigit ;
            digitProduct *= currentDigit ; 


        }

        return n % ( digitSum + digitProduct ) == 0 ;
    }
};