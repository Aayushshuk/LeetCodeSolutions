class Solution {
public:
    bool isPalindrome(int x){
        if(x<0){
            return false;
        }
       
        long long rev=0;
        long long  number=x;
        while(number !=0){
            rev = rev*10 + number %10;
            number/=10; 
        }
       return rev == x;
    }
};