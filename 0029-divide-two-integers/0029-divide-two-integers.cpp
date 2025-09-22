class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) 
            return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        bool sign = true;
        if(dividend >=0 && divisor < 0)  sign = false;
        else if(dividend <= 0 && divisor > 0)  sign = false;
        long n = dividend;
        long d = divisor;
        n = abs(n);
        d = abs(d);
    
        int ans =0;
        while(n >= d){
            int count =0;
            while(n >= (d << (count+1))){
                count+=1;
            }
            ans += 1<<count;
            n -= (d<<count);
        }
        if(ans == (1<<31) && sign){
            return INT_MAX;        
        }

        if(ans == (1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? ans : -ans;
    }
};