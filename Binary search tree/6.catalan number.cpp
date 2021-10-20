#include<bits/stdc++.h>
using namespace std;

// catlan no basically to count no of bst num=2nCn/(n+1) && total no.. of binary tree =  num*(n!)
     long long int binCoeff(int n, int k){
        long long int res = 1;
        for(int i = 0; i < k; i++){
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    
    long long int countBST(int n){
        long long int c = binCoeff(2*n, n); 
        return c/(n+1); // catalan number = (2n!)/(n+1!)*(n!)
    }
