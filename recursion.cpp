//Pow()

class Solution {
public:
    double solvePow(double x,int n){
        if(n==0)return 1.0;
        double half=solvePow(x,n/2);
        if(n%2==0)return half*half;
        else return half*half*x;
    }
    double myPow(double x, int n) {
        if(n<0)return 1/solvePow(x,n);
        return solvePow(x,n);
    }
};

