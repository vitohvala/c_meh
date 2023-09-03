double myPow(double x, long n){
    if ( x == 0 || n == 1) return x;
    if ( n == 0 ) return 1;
    if(n < 0) return myPow(1 / x, -n);

    double result = myPow(x * x, n / 2);

    if(n % 2) result *= x;
    return result;
}